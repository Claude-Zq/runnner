//
// Created by 周青 on 2022/5/24.
//

#pragma once
typedef  struct date {
    int year;
    short month;
    short day;
}DATE;


//传入一个日期，判断日期是否合法
//合法:1
//非法:0
int IsLegalDate(DATE *d);

//传入一个年份，判断其是否是闰年
//是：1
//不是：0
int IsLeap(int year);


//获取指定月份的天数,出错返回0
int GetDays(int year,int month);

//以0000-00-03为基准,将日期转换为天数(返回值%7+1即为星期数)
int DateToDays(DATE *d);

//判断两个日期的是否在同一个礼拜
int InSameWeek(DATE *d1,DATE *d2);

//判断两个日期是否在同一月份
int InSameMonth(DATE *d1,DATE *d2);

//判断两日期是否在同一年份
int InSameYear(DATE *d1,DATE *d2);

//比较两个日期
//d1 < d2: 1
//d1 = d2: 0
//d1 > d2: -1
int DateCmp(DATE *d1,DATE *d2);