//
// Created by 周青 on 2022/5/24.
//

#pragma once
#include "record.h"
#define MAXLENGTH 100 //每行数据的最大长度
#define INITIALCAP 8 //recordsArray的初始容量


struct recordsA{
    RECORD * records;
    int size,cap;
}recordsArray;

//将文件中的记录导入到recordsArray中
void InitRecordsArray();


//将recordsArray中的信息保存到文件中
int SaveRecordsArray();

//将recordsArray容量扩为两倍
int DoubleArrayCap();


//按距离对记录排序(升序)
void SortRecordsArrayByDistance();

//按时间对记录排序(升序)
void SortRecordsArrayByDate();
