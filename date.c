//
// Created by 周青 on 2022/5/24.
//

#include "date.h"
//一周的开始是周一

//常量定义在头文件中会报错
//元时间，记录不能早于该时间点
const DATE METATIME = {0000,00,3};

//记录每月的天数
//第DAY[0][j]表示平年第j月的天数
//第DAY[1][j]表示闰年第j月的天数
int DAYS[2][13]= {
        {0,31,28,31,30,31,30,31,31,30,31,30,31},
        {0,31,29,31,30,31,30,31,31,30,31,30,31}};


int IsLegalDate(DATE *d){
    if (d->year<METATIME.year) return 0;
    if (d->month<1||d->month>12) return 0;
    if (d->day<0 ||d->day> GetDays(d->year,d->month)) return 0;
    return 1;
}

int GetDays(int year,int month){
    if (year<0 || month<0 ||month>12 ) return 0; //检查日期合法性
    if (month != 2) return DAYS[0][month];  //不是二月
    else return DAYS[(IsLeap(year))][2];  //二月份
}

int IsLeap(int year){
    if (year < 0)  {return 0;} //年份不合法
    if ((year%4==0 && year%100!=0 )|| year%400==0){return 1;}
    else{return 0;}
}

int DateToDays(DATE *d){
    int ret = -3;
    for(int i = 0;i<d->year;i++) ret += IsLeap(i)? 366 :  365;
    for(int i = 1;i<d->month;i++) ret += GetDays(d->year,i);
    ret += d->day;
    return ret;
}

int InSameWeek(DATE *d1,DATE *d2){
    int days1 = DateToDays(d1),days2 = DateToDays(d2);
    return days1/7 == days2/7;
}

int InSameMonth(DATE *d1,DATE *d2){
    return d1->year == d2->year && d1->month==d2->month;
}

int InSameYear(DATE *d1,DATE *d2){
    return d1->year == d2->year;
}

int DateCmp(DATE *d1,DATE *d2){
    if (d1->year !=  d2->year) return d1->year < d2->year? 1 :-1; //先比较年
    if (d1->month != d2->month) return d1->month < d2->month? 1:-1; //再比较月
    if (d1->day != d2->day) return d1->day <d2->day? 1:-1; //最后比较日
    return 0; //都相同则说明是同一天
}
