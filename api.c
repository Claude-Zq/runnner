//
// Created by 周青 on 2022/5/24.
//

#include "api.h"

void ShowMenu(){
    printf("***************************************************\n");
    printf("***************************************************\n");
    printf("******************    RUNNER      *****************\n");
    printf("******************  1.添加记录    *****************\n");
    printf("******************  2.删除记录    *****************\n");
    printf("******************  3.查找记录    *****************\n");
    printf("******************  4.分析记录    *****************\n");
    printf("******************  0.退出程序    *****************\n");
    printf("***************************************************\n");
    printf("***************************************************\n");
}


int* SelectRecordsByDate(DATE*a,DATE*b){
    int *ret =(int*)malloc(sizeof(int));
    *ret = 0;
    for (int i = 0;i<recordsArray.size;i++) {
        //满足条件，记录索引
        if (DateCmp(a, &recordsArray.records[i].date) > 0 && DateCmp(&recordsArray.records[i].date, b) > 0) {
            ret[0]++;
            //重新分配内存
            ret = (int *) realloc(ret, ret[0] + 1);
            if (ret == NULL) {
                printf("SelectRecordsByDate中内存申请失败");
                return ret;
            }
            ret[ret[0]] = i;//存储满足条件的记录在recordsArray中的索引
        }
    }
    return ret;
}


int* SelectRecordsByDuration(float a,float b){
    int *ret =(int*)malloc(sizeof(int));
    *ret = 0;
    for (int i = 0;i<recordsArray.size;i++) {
        //满足条件，记录索引
        if (recordsArray.records[i].duration>=a &&recordsArray.records[i].duration<=b) {
            ret[0]++;
            //重新分配内存
            ret = (int *) realloc(ret, ret[0] + 1);
            if (ret == NULL) {
                printf("SelectRecordsByDate中内存申请失败");
                return ret;
            }
            ret[ret[0]] = i;//存储满足条件的记录在recordsArray中的索引
        }
    }
    return ret;
}


int* SelectRecordsByDistance(float a,float b){
    int *ret =(int*)malloc(sizeof(int));
    *ret = 0;
    for (int i = 0;i<recordsArray.size;i++) {
        //满足条件，记录索引
        if (recordsArray.records[i].distance>=a &&recordsArray.records[i].distance<=b) {
            ret[0]++;
            //重新分配内存
            ret = (int *) realloc(ret, ret[0] + 1);
            if (ret == NULL) {
                printf("SelectRecordsByDate中内存申请失败");
                return ret;
            }
            ret[ret[0]] = i;//存储满足条件的记录在recordsArray中的索引
        }
    }
    return ret;
}

void ShowRecords(const int *ret){
    if (ret[0]==0) {
        printf("无满足条件的记录\n");
        return;
    }
    else{
        printf("===查询结果如下===\n");
        printf("   %s    \t %s \t%s\t   %s\n","日期","时长","距离","类别");
        for (int i = 1;i<=ret[0];i++){
            printf("%04d-%02d-%02d\t%4.2f\t%4.2f\t%d\n",
                   recordsArray.records[ret[i]].date.year,
                   recordsArray.records[ret[i]].date.month,
                   recordsArray.records[ret[i]].date.day,
                   recordsArray.records[ret[i]].duration,
                   recordsArray.records[ret[i]].distance,
                   recordsArray.records[ret[i]].category);
        }
    }
    free(ret);//释放堆区开辟的内存
}