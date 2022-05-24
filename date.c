//
// Created by 周青 on 2022/5/24.
//

#include "date.h"
//一周的开始是周日

//常量定义在头文件中会报错
//元时间，记录不能早于该时间点
const DATE METATIME = {0000,00,3};

//记录每月的天数
//第DAY[0][j]表示平年第j月的天数
//第DAY[1][i]表示闰年第j月的天数
int DAYS[2][13]= {
        {0,31,28,31,30,31,30,31,31,30,31,30,31},
        {0,31,29,31,30,31,30,31,31,30,31,30,31}};


//判断日期是否合法 合法：1 不合法：0
int IsLegalDate(DATE *d){
    if (d->year<METATIME.year) return 0;
    if (d->month<1||d->month>12) return 0;
    if (d->day<0 ||d->day> GetDays(d->year,d->month)) return 0;
    return 1;
}


//获取指定月份的天数,出错返回0
int GetDays(int year,int month){
    if (year<0 || month<0 ||month>12 ) return 0;
    if (month != 2) return DAYS[0][month];
    else return DAYS[(IsLeap(year))][2];
}




//判断是否时闰年 是：1 不是：0
int IsLeap(int year){
    if (year < 0)  {return 0;}
    if ((year%4==0 && year%100!=0 )|| year%400==0){return 1;}
    else{return 0;}
}

//以0000-00-03日为基准,将日期转换为天数(返回值%7+1即为星期数)
int DateToDays(DATE *d){
    int ret = -3;
    for(int i = 0;i<d->year;i++) ret += IsLeap(i)? 366 :  365;
    for(int i = 1;i<d->month;i++) ret += GetDays(d->year,i);
    ret += d->day;
    return ret;
}


//判断两个日期的是否在同一个礼拜
int InSameWeek(DATE *d1,DATE *d2){
    int days1 = DateToDays(d1),days2 = DateToDays(d2);
    return days1/7 == days2/7;
}

//判断两个日期是否在同一月份
int InSameMonth(DATE *d1,DATE *d2){
    return d1->year == d2->year && d1->month==d2->month;
}

//判断两日期是否在同一年份
int InSameYear(DATE *d1,DATE *d2){
    return d1->year == d2->year;
}

//比较两个日期
//d1 < d2: 1
//d1 = d2: 0
//d1 > d2: -1
int DateCmp(DATE *d1,DATE *d2){
    if (d1->year !=  d2->year) return d1->year < d2->year? 1 :-1;
    if (d1->month != d2->month) return d1->month < d2->month? 1:-1;
    if (d1->day != d2->day) return d1->day <d2->day? 1:-1;
    return 0;
}
