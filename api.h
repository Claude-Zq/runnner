//
// Created by 周青 on 2022/5/24.
//
#pragma once
#include<stdio.h>
#include "date.h"
#include"record.h"
#include<stdlib.h>
#include"fileManager.h"
#include <math.h>
#define EPS 1e-8        //浮点误差

extern const char* cateIdToString[]; //用到record.c中定义的全局变量，必须重新声明一遍

//展示菜单
void ShowMenu();


//按日期区间查找对应记录
//函数参数：起始日期a 终止日期b
//函数返回值：一个数组ret(int *)，ret[0]记录结果个数,ret[1]开始记录recordsArray.records中复合条件的索引(用后记得free)
int* SelectRecordsByDate(DATE*a,DATE*b);

//按时长区间查找对应记录
//函数参数: 最低时长a 最高时长b
//函数返回值：一个数组ret(int *)，ret[0]记录结果个数,ret[1]开始记录recordsArray.records中复合条件的索引(用后记得free)
int* SelectRecordsByDuration(float a,float b);

//按距离区间查找对应记录
//函数参数: 最短时长a 最长时长b
//函数返回值：一个数组ret(int *)，ret[0]记录结果个数,ret[1]开始记录recordsArray.records中复合条件的索引(用后记得free)
int* SelectRecordsByDistance(float a,float b);


//按跑步类别查找对应记录
//函数参数: 分类编号
//函数返回值：一个数组ret(int *)，ret[0]记录结果个数,ret[1]开始记录recordsArray.records中复合条件的索引(用后记得free)
int* SelectRecordsByCate(int cateID);

//展示查找到的记录
void ShowRecords(const int *ret);

//查找记录(汇总)
void SelectRecords();

//展示各年跑量
void ShowAnnualMileage();


//展示各月跑量
void ShowMonthlyMileage();

//展示周跑量
void ShowWeeklyMileage();


//按距离顺序输出所有跑步记录
//isReverse = 1 逆序输出
//isReverse = 0 顺序输出
void ShowAllRecords(int isReverse);

//展示周跑量的组成
void ShowWeeklyMileageComposition();

//分析记录
void  AnalyzeRecord();

//添加记录
void AddRecord();


//删除记录
void DeleteRecord();