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
        if (DateCmp(a, &recordsArray.records[i].date) >= 0 && DateCmp(&recordsArray.records[i].date, b) >= 0) {
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


int* SelectRecordsByCate(int cateID){
    int *ret =(int*)malloc(sizeof(int));
    *ret = 0;
    for (int i = 0;i<recordsArray.size;i++) {
        //满足条件，记录索引
        if (cateID == recordsArray.records[i].category) {
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
        printf("无满足条件的记录!\n");
        return;
    }
    else{
        printf("\t\t===查询结果如下===\n");
        printf("    日期     时长     距离       类别\n");
        for (int i = 1;i<=ret[0];i++){
            printf("%04d-%02d-%02d \t%4.2f\t%4.2f\t%s\n",
                   recordsArray.records[ret[i]].date.year,
                   recordsArray.records[ret[i]].date.month,
                   recordsArray.records[ret[i]].date.day,
                   recordsArray.records[ret[i]].duration,
                   recordsArray.records[ret[i]].distance,
                   cateIdToString[recordsArray.records[ret[i]].category]);
        }
    }
    free(ret);//释放堆区开辟的内存
}


void SelectRecords() {
    printf("1.按日期查找\n2.按时长查找\n3.按距离查找\n4.按分类查找\n0.返回上一级\n请输入您的选择:");
    int select,ignore;
    while (scanf("%d",&select)!= 1){
        printf("输入错误请重新输入:");
        while ((ignore = getchar()) != '\n');//清空输入缓冲区用scanf(“%*[^\n]%*c”)会遗留回车符
    }
    while ((ignore = getchar()) != '\n');//清空输入缓冲区

    int * ret;
    switch (select)
    {
        case 0://返回上一级
            printf("已返回\n");
            return;
        case 1://按日期查找
        {
            DATE start,end;
            printf("请输入起始日期(yyyy/mm/dd):");
            while(1) {
                while (scanf("%d/%hd/%hd", &start.year, &start.month, &start.day) != 3) {
                    printf("日期格式有误，请重新输入:");
                    while ((ignore = getchar()) != '\n');//清空输入缓冲区用scanf(“%*[^\n]%*c”)会遗留回车符
                }
                if (IsLegalDate(&start)) break;
                printf("输入日期不合法，请重新输入:");
            }
            while ((ignore = getchar()) != '\n');//清空输入缓冲区

            printf("请输入终止日期(yyyy/mm/dd):");
            while(1){
                while (scanf("%d/%hd/%hd",&end.year,&end.month,&end.day)!= 3){
                    printf("日期格式有误，请重新输入:");
                    while ((ignore = getchar()) != '\n');//清空输入缓冲区用scanf(“%*[^\n]%*c”)会遗留回车符
                }
                if (IsLegalDate(&end)) break;
                printf("输入日期不合法，请重新输入:");
            }
            while ((ignore = getchar()) != '\n');//清空输入缓冲区

            if (DateCmp(&start,&end)==-1){
                printf("起始时间不得大于终止时间!\n");
                return;
            }
            ret = SelectRecordsByDate(&start,&end);
            break;
        }

        case 2://按时长查找
        {
            float minT,maxT;
            printf("请输入最短时长(单位:h):");
            while (scanf("%f", &minT) != 1) {
                printf("输入有误，请重新输入:");
                while ((ignore = getchar()) != '\n');//清空输入缓冲区用scanf(“%*[^\n]%*c”)会遗留回车符
            }
            while ((ignore = getchar()) != '\n');//清空输入缓冲区

            printf("请输入最长时长(单位:h):");
            while (scanf("%f", &maxT) != 1) {
                printf("输入有误，请重新输入:");
                while ((ignore = getchar()) != '\n');//清空输入缓冲区用scanf(“%*[^\n]%*c”)会遗留回车符
            }
            while ((ignore = getchar()) != '\n');//清空输入缓冲区

            if (minT>maxT){
                printf("最短时长不得大于最大时长!\n");
                return;
            }
            ret = SelectRecordsByDuration(minT,maxT);
            break;
        }

        case 3://按距离查找
        {
            float minD,maxD;
            printf("请输入最短距离(单位:km):");
            while (scanf("%f", &minD) != 1) {
                printf("输入有误，请重新输入:");
                while ((ignore = getchar()) != '\n');//清空输入缓冲区用scanf(“%*[^\n]%*c”)会遗留回车符
            }
            while ((ignore = getchar()) != '\n');//清空输入缓冲区

            printf("请输入最长距离(单位:km):");
            while (scanf("%f", &maxD) != 1) {
                printf("输入有误，请重新输入:");
                while ((ignore = getchar()) != '\n');//清空输入缓冲区用scanf(“%*[^\n]%*c”)会遗留回车符
            }
            while ((ignore = getchar()) != '\n');//清空输入缓冲区

            if (minD>maxD){
                printf("最短距离不得大于最大距离!\n");
                return;
            }
            ret = SelectRecordsByDistance(minD,maxD);
            break;
        }
        case 4://按分类查找
        {
            short cateID;

            printf("1.EasyRunning\n2.LongSlowDistance\n3.MarathonPaceRunning\n4.ThresholdRunning\n5.IntervalTraining\n");
            printf("请输入您想查找的类别:");
            while (scanf("%hd", &cateID) != 1) {
                printf("输入有误，请重新输入:");
                while ((ignore = getchar()) != '\n');//清空输入缓冲区用scanf(“%*[^\n]%*c”)会遗留回车符
            }
            while ((ignore = getchar()) != '\n');//清空输入缓冲区

            if (cateID<1||cateID>5){
                printf("无该类别!\n");
                return;
            }
            ret = SelectRecordsByCate(cateID);
            break;
        }
        default:
            printf("无该选项！");
            return;
    }
    ShowRecords(ret);
}


void ShowAnnualMileage(){
    //记录为空
    if (recordsArray.size == 0){
        printf("记录为空");
        return;
    }
    SortRecordsArrayByDate();//确保记录的顺序是升序排列的

    float sumOfMileage = 0; //年跑量
    DATE LastDate =  recordsArray.records[0].date;
    for(int i = 0;i< recordsArray.size;i++){
        //和上一个日期同年，继续向sumOfMileage中叠加
        if(InSameYear(&LastDate,&recordsArray.records[i].date)){
            sumOfMileage  += recordsArray.records[i].distance;
        }
            //和上一个日期不同年
        else{
            //输出旧年的跑量
            printf("%04d年:",LastDate.year);
            for(int j = (int)(0.5*(sumOfMileage+0.5));j>0;j--) printf("#"); //输出进度条
            printf(" %.2fkm\n",sumOfMileage );
            sumOfMileage  = recordsArray.records[i].distance;//开始计算新一年的跑量
        }
        LastDate = recordsArray.records[i].date;
    }
    //最后一年没有输出
    if(fabsf(sumOfMileage-0)>EPS){
        printf("%04d年:",LastDate.year);
        for(int j = (int)(0.5*(sumOfMileage+0.5));j>0;j--) printf("#"); //输出进度条
        printf(" %.2fkm\n",sumOfMileage );
    }

}


void ShowMonthlyMileage(){
    //记录为空
    if (recordsArray.size == 0){
        printf("记录为空");
        return;
    }
    SortRecordsArrayByDate();//确保记录的顺序是升序排列的

    float sumOfMileage = 0; //月跑量
    DATE LastDate =  recordsArray.records[0].date;
    for(int i = 0;i< recordsArray.size;i++){
        //和上一个日期同月，继续向sumOfMileage中叠加
        if(InSameMonth(&LastDate,&recordsArray.records[i].date)){
            sumOfMileage  += recordsArray.records[i].distance;
        }
            //和上一个日期不同月
        else{
            //输出旧月的跑量
            printf("%04d-%02d:",LastDate.year,LastDate.month);
            for(int j = (int)(sumOfMileage+0.5);j>0;j--) printf("#"); //输出进度条
            printf(" %.2fkm\n",sumOfMileage );
            sumOfMileage  = recordsArray.records[i].distance;//开始计算新月的跑量
        }
        LastDate = recordsArray.records[i].date;
    }
    //最后一月没有输出
    if(fabsf(sumOfMileage-0)>EPS){
        printf("%04d-%02d:",LastDate.year,LastDate.month);
        for(int j = (int)(sumOfMileage+0.5);j>0;j--) printf("#"); //输出进度条
        printf(" %.2fkm\n",sumOfMileage );
    }

}


void ShowWeeklyMileage(){
    //记录为空
    if (recordsArray.size == 0){
        printf("记录为空");
        return;
    }
    SortRecordsArrayByDate();//确保记录的顺序是升序排列的

    float sumOfMileage = 0; //周跑量
    int weekId = 1;
    DATE LastDate =  recordsArray.records[0].date;
    for(int i = 0;i< recordsArray.size;i++){
        //和上一个日期同周，继续向sumOfMileage中叠加
        if(InSameWeek(&LastDate,&recordsArray.records[i].date)){
            sumOfMileage  += recordsArray.records[i].distance;
        }
            //和上一个日期不同周
        else{
            //输出旧月的跑量
            printf("%03d周:",weekId++);
            for(int j = 3*(int)(sumOfMileage+0.5);j>0;j--) printf("#"); //输出进度条
            printf(" %.2fkm\n",sumOfMileage );
            sumOfMileage  = recordsArray.records[i].distance;//开始计算新月的跑量
        }
        LastDate = recordsArray.records[i].date;
    }
    //最后一周没有输出
    if(fabsf(sumOfMileage-0)>EPS){
        printf("%03d周:",weekId);
        for(int j = (int)(sumOfMileage+0.5);j>0;j--) printf("#"); //输出进度条
        printf(" %.2fkm\n",sumOfMileage );
    }


}


//按距离顺序输出所有跑步记录
void ShowAllRecords(int isReverse){
    if (recordsArray.size == 0){
        printf("无任何记录！\n");
        return;
    }

    printf("       ===查询结果如下===\n");
    printf("   %s    \t %s \t%s\t   %s\n","日期","时长","距离","类别");
    //将记录升序排列
    SortRecordsArrayByDistance();
    if (isReverse == 1){
        for (int i = recordsArray.size-1;i>=0;i--){
            printf("%04d-%02d-%02d\t%4.2f\t%4.2f\t%d\n",
                   recordsArray.records[i].date.year,
                   recordsArray.records[i].date.month,
                   recordsArray.records[i].date.day,
                   recordsArray.records[i].duration,
                   recordsArray.records[i].distance,
                   recordsArray.records[i].category);
        }
    }
    else{
        for (int i = 0;i<recordsArray.size;i++){
            printf("%04d-%02d-%02d\t%4.2f\t%4.2f\t%d\n",
                   recordsArray.records[i].date.year,
                   recordsArray.records[i].date.month,
                   recordsArray.records[i].date.day,
                   recordsArray.records[i].duration,
                   recordsArray.records[i].distance,
                   recordsArray.records[i].category);
        }
    }

}


//展示周跑量的组成
void ShowWeeklyMileageComposition(){
    //记录为空
    if (recordsArray.size == 0){
        printf("记录为空\n");
        return;
    }
    SortRecordsArrayByDate();//确保记录的顺序是升序排列的

    //记录每周各类别的跑量
    float sumOfMileage[5] = {0,0,0,0,0} ;
    int weekId = 1;

    DATE LastDate =  recordsArray.records[0].date;
    for(int i = 0;i< recordsArray.size;i++){
        //和上一个日期同周，继续向sumOfMileage中叠加
        if(InSameWeek(&LastDate,&recordsArray.records[i].date)){
            sumOfMileage[recordsArray.records[i].category-1] += recordsArray.records[i].distance;
        }
            //和上一个日期不同周
        else{
            //输出旧周的跑量组成
            printf("%03d周:\n",weekId++);

            //计算本周总跑量
            float sum = 0;
            for (int j = 0;j<NUMOFCATE;j++) sum += sumOfMileage[j];

            for(int j = 0;j<NUMOFCATE;j++){
                printf("[%c]  %%%06.2f:  ",cateIdToString[j+1][0],sumOfMileage[j]/sum*100);
                for (int k = 0;k<(int)sumOfMileage[j]*2;k++) printf("#");
                printf("\n");
            }
            sumOfMileage[recordsArray.records[i].category-1]  = recordsArray.records[i].distance;//开始计算新周的跑量
        }
        LastDate = recordsArray.records[i].date;
    }
    //输出最后一周
    printf("%03d周:\n",weekId++);
    //计算本周总跑量
    float sum = 0;
    for (int j = 0;j<NUMOFCATE;j++) sum += sumOfMileage[j];

    for(int j = 0;j<NUMOFCATE;j++){
        printf("[%c]  %%%06.2f:  ",cateIdToString[j+1][0],sumOfMileage[j]/sum*100);
        for (int k = 0;k<(int)sumOfMileage[j]*2;k++) printf("#");
        printf("\n");
    }
}




void AddRecord(){
    RECORD newR;

    //输入日期
    printf("请输入日期(yyyy/mm/dd):");
    int ignore;
    while(1) {

        while (scanf("%d/%hd/%hd", &newR.date.year, &newR.date.month, &newR.date.day) != 3) {
            printf("日期格式有误，请重新输入:");
            while ((ignore = getchar()) != '\n');//清空输入缓冲区用scanf(“%*[^\n]%*c”)会遗留回车符
        }
        //输入日期合法时，才跳出循环
        if (IsLegalDate(&newR.date)) break;
        printf("输入日期不合法，请重新输入:");
    }
    while ((ignore = getchar()) != '\n');//清空输入缓冲区

    //输入时长
    printf("请输入时长(单位:h):");
    while (scanf("%f", &newR.duration) != 1) {
        printf("输入有误，请重新输入:");
        while ((ignore = getchar()) != '\n');//清空输入缓冲区用scanf(“%*[^\n]%*c”)会遗留回车符
    }
    while ((ignore = getchar()) != '\n');//清空输入缓冲区

    //输入距离
    printf("请输入距离(单位:km):");
    while (scanf("%f", &newR.distance) != 1) {
        printf("输入有误，请重新输入:");
        while ((ignore = getchar()) != '\n');//清空输入缓冲区用scanf(“%*[^\n]%*c”)会遗留回车符
    }
    while ((ignore = getchar()) != '\n');//清空输入缓冲区

    //输入类别
    printf("请输入类别:\n1.EasyRunning\n2.LongSlowDistance\n3.MarathonPaceRunning\n4.ThresholdRunning\n5.IntervalTraining\n");
    while (scanf("%d", &newR.category) != 1) {
        printf("输入有误，请重新输入:");
        while ((ignore = getchar()) != '\n');//清空输入缓冲区用scanf(“%*[^\n]%*c”)会遗留回车符
    }
    while ((ignore = getchar()) != '\n');//清空输入缓冲区

    AddRecordToArray(&newR);
    SaveRecordsArray();
    printf("添加成功！\n");
}



void DeleteRecord(){
    DATE date;
    //输入日期
    printf("请输入待删除记录的日期(yyyy/mm/dd):");
    int ignore;
    while(1) {

        while (scanf("%d/%hd/%hd", &date.year, &date.month, &date.day) != 3) {
            printf("日期格式有误，请重新输入:");
            while ((ignore = getchar()) != '\n');//清空输入缓冲区用scanf(“%*[^\n]%*c”)会遗留回车符
        }
        //输入日期合法时，才跳出循环
        if (IsLegalDate(&date)) break;
        printf("输入日期不合法，请重新输入:");
    }
    while ((ignore = getchar()) != '\n');//清空输入缓冲区

    if (DeleteRecordByDate(&date)==1) printf("删除成功！\n");
    else printf("当天无跑步记录\n");
}
