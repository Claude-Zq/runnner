#include <stdio.h>
#include"fileManager.h"
#include "api.h"

int main() {

    InitRecordsArray();

    //测试fileManger中的所有函数
/*    //输出所有记录
    for(int i = 0;i<recordsArray.size;i++){
        printf("%04d-%02d-%02d\t%4.2f\t%4.2f\t%d\n",
               recordsArray.records[i].date.year,
               recordsArray.records[i].date.month,
               recordsArray.records[i].date.day,
               recordsArray.records[i].duration,
               recordsArray.records[i].distance,
               recordsArray.records[i].category);
    }*/
   /* SortRecordsArrayByDistance();
    //输出所有记录
    for(int i = 0;i<recordsArray.size;i++){
        printf("%04d-%02d-%02d\t%4.2f\t%4.2f\t%d\n",
               recordsArray.records[i].date.year,
               recordsArray.records[i].date.month,
               recordsArray.records[i].date.day,
               recordsArray.records[i].duration,
               recordsArray.records[i].distance,
               recordsArray.records[i].category);
    }
    */

//    SortRecordsArrayByDate();
//    //输出所有记录
//    for(int i = 0;i<recordsArray.size;i++){
//        printf("%04d-%02d-%02d\t%4.2f\t%4.2f\t%d\n",
//               recordsArray.records[i].date.year,
//               recordsArray.records[i].date.month,
//               recordsArray.records[i].date.day,
//               recordsArray.records[i].duration,
//               recordsArray.records[i].distance,
//               recordsArray.records[i].category);
//    }


    /*ShowMenu();*/


    /*DATE d1 = {2022,4,4},d2 = {2022,5,5};
    int * ret = SelectRecordsByDate(&d1,&d2);
    ShowRecords(ret);*/

  /* float t1 = (float)0.5,t2 = 1;
    int * ret = SelectRecordsByDuration(t1,t2);
    ShowRecords(ret);*/

   /* float d1 = 5,d2 = 10;
    int * ret = SelectRecordsByDistance(d1,d2);
    ShowRecords(ret);*/

   /*int *ret = SelectRecordsByCate(6);
    ShowRecords(ret);*/


    /*SelectRecords();*/

    /*ShowAnnualMileage();*/

    /*ShowMonthlyMileage();*/

    /*ShowWeeklyMileage();*/

    /*ShowAllRecords(1);*/

    ShowWeeklyMileageComposition();

    return 0;
}
