//
// Created by 周青 on 2022/5/24.
//

#include "fileManager.h"
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>


//将文件中的记录导入到recordsArray中
void InitRecordsArray(){
    //初始化化recordsArray
    recordsArray.records = malloc(INITIALCAP*sizeof(RECORD));
    recordsArray.size = 0,recordsArray.cap = INITIALCAP;

    //打开文件
    FILE *fp;
    if  ((fp=fopen("../records.txt","r")) == NULL){
        printf("文件打开失败");
        exit(1);
    }
    char buff[MAXLENGTH+1];
    //读取文件
    while (fgets(buff,MAXLENGTH,fp)!=NULL){
        RECORD temp;
        if (sscanf(buff,"%d %hd %hd %f %f %d",&temp.date.year,&temp.date.month,&temp.date.day,&temp.duration,&temp.distance,&temp.category)!= 6){
            printf("数据导入出错");
            exit(1);
        }
        if(recordsArray.size == recordsArray.cap) DoubleArrayCap(); //保证不会溢出
        recordsArray.records[recordsArray.size] = temp;
        recordsArray.size++; //记录数增一
    }
    //关闭文件
    fclose(fp);
}

//将recordsArray中的信息保存到文件中 没有free recordsArray的空间
int SaveRecordsArray(){
    //打开文件
    FILE *fp;
    if  ((fp=fopen("../records.txt","w")) == NULL){
        printf("文件打开失败");
        exit(1);
    }
    for (int i = 0;i<recordsArray.size;i++){
        if (fprintf(fp,"%04d %02d %02d %8.4f %8.4f %d\n",
                    recordsArray.records[i].date.year,recordsArray.records[i].date.month,recordsArray.records[i].date.day,
                    recordsArray.records[i].duration,recordsArray.records[i].distance,recordsArray.records[i].category) < 0){
            printf("保存失败\n");
        }
    }

    //关闭文件
    fclose(fp);

}



//将recordsArray容量扩为两倍
//扩容成功: 1
//扩容失败: 0
int DoubleArrayCap(){
    //开辟新的内存空间
    RECORD* newRecords =(RECORD*) realloc(recordsArray.records,recordsArray.cap*2*sizeof(RECORD)); //realloc会自动free原来的空基恩
    if (newRecords == NULL){ //内存不足时不会释放原来空间
        printf("recordsArray扩容失败\n");
        return 0;
    }
    recordsArray.cap *= 2;
    recordsArray.records = newRecords;
    return 1;
}


//按距离对记录排序(升序)
void SortRecordsArrayByDistance(){
    for(int i = 0;i<recordsArray.size-1;i++){
        int minIndex = i;
        for(int j = i+1;j< recordsArray.size;j++){
            if(recordsArray.records[j].distance<recordsArray.records[minIndex].distance){
                minIndex = j;
            }
        }
        if (minIndex != i){
            RECORD temp = recordsArray.records[minIndex];
            recordsArray.records[minIndex] = recordsArray.records[i];
            recordsArray.records[i] = temp;
        }
    }
}


//按时间对记录排序(升序)
void SortRecordsArrayByDate(){
    for(int i = 0;i<recordsArray.size-1;i++){
        int minIndex = i;
        for(int j = i+1;j< recordsArray.size;j++){
            if(DateCmp(&recordsArray.records[j].date,&recordsArray.records[minIndex].date)==1){
                minIndex = j;
            }
        }
        if (minIndex != i){
            RECORD temp = recordsArray.records[minIndex];
            recordsArray.records[minIndex] = recordsArray.records[i];
            recordsArray.records[i] = temp;
        }
    }
}