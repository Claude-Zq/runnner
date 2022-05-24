#include <stdio.h>
#include"fileManager.h"

int main() {

    InitRecordsArray();
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


    return 0;
}
