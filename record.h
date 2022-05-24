//
// Created by 周青 on 2022/5/24.
//

#pragma once
#include "date.h"
#define NUMOFCATE 5

typedef enum cate{
    EasyRunning = 1,LongSlowDistance,MarathonPaceRunning,ThresholdRunning,IntervalTraining
}CATE;

typedef struct record{
    DATE date; //年月日
    float duration;//单位(h)
    float distance;//单位(km)
    CATE category;//类别
}RECORD;