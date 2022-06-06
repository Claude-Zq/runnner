//
// Created by 周青 on 2022/5/24.
//

#include "fileManager.h"
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>


void InitRecordsArray(){
    //初始化化recordsArray
    recordsArray.records = malloc(INITIALCAP*sizeof(RECORD));
    recordsArray.size = 0,recordsArray.cap = INITIALCAP;

    //打开文件
    FILE *fp;
    if  ((fp=fopen(FILENAME,"r")) == NULL){
        system("pwd");
        system("ls");
        printf("%s",FILENAME);
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

void SaveRecordsArray(){
    //打开文件
    FILE *fp;
    if  ((fp=fopen(FILENAME,"w")) == NULL){
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

int DoubleArrayCap(){
    //开辟新的内存空间
    RECORD* newRecords =(RECORD*) realloc(recordsArray.records,recordsArray.cap*2*sizeof(RECORD)); //realloc会自动free原来的空间
    if (newRecords == NULL){ //内存不足时不会释放原来空间
        return 0;
    }
    recordsArray.cap *= 2;
    recordsArray.records = newRecords;
    return 1;
}

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

void AddRecordToArray(RECORD *rcd){
    //recordsArray满了，扩容
    if (recordsArray.size == recordsArray.cap)
        if(DoubleArrayCap()!=1) printf("扩容失败\n");
    recordsArray.records[recordsArray.size] = *rcd;
    recordsArray.size++;

}

int DeleteRecordByDate(DATE *date){
    //查找记录在recordsArray中索引
    int index = -1;
    for(int i = 0;i<recordsArray.size;i++){
        if(DateCmp(&recordsArray.records[i].date,date)==0) {
            index = i;
            break;
        }
    }
    //没有该日期对应的记录
    if (index == -1) return 0;

    //删除指定记录(覆盖法）

    //刚好是最后一个
    if(index==recordsArray.size-1){
        recordsArray.size -= 1; //逻辑上的删除
    }
    else{
        for(int i = index+1;i< recordsArray.size;i++){
            recordsArray.records[i-1] = recordsArray.records[i];
        }
        recordsArray.size -= 1;
    }

    //将删除后的记录保存到文件中
    SaveRecordsArray();
    return 1;
}