//
// Created by 周青 on 2022/5/24.
//

#pragma once
#include "record.h"
#define MAXLENGTH 100 //每行数据的最大长度
#define INITIALCAP 8 //recordsArray的初始容量
#define FILENAME "/Users/zhouqing/Documents/devFile/c:c++/runner-v2/records.txt"


struct recordsA{
    RECORD * records;
    int size,cap;
}recordsArray;
//在GCC编译环境下，全局结构体变量可以直接定义在头文件中，并且和我们想要的一样，所有包含该
//头文件的文件共用这一个变量
//在windows中的VS编译环境下，把全局结构体变量定义在头文件中会报错，提示重复定义变量

//将文件中的记录导入到recordsArray中
void InitRecordsArray();


//将recordsArray中的信息保存到文件中(没有释放recordsArray，所以可以继续用)
void SaveRecordsArray();

//将recordsArray容量扩为两倍
//成功：1
//失败：0
int DoubleArrayCap();


//按距离对记录排序(升序)
void SortRecordsArrayByDistance();

//按时间对记录排序(升序)
void SortRecordsArrayByDate();

//判断当天是否已有记录（使用二分查找）
//已经记录：1
//没有记录：0
int IsRecorded(DATE *d);


//添加记录
void AddRecordToArray(RECORD *rcd);


//按日期删除记录
//函数参数：待删除记录的日期 的指针
//函数返回值：
//1 当天有记录并删除成功
//0 当天无记录
int DeleteRecordByDate(DATE *d);