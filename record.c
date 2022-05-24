//
// Created by 周青 on 2022/5/24.
//
#include "record.h"

/*缩影为分类编号 值为对应的字符串
1 - EasyRunning
2 - LongSlowDistance
3 - MarathonPaceRunning
4 - ThresholdRunning
5 - IntervalTraining*/
const char* cateIdToString[NUMOFCATE+1] = {
        "占位",
        "EasyRunning",
        "LongSlowDistance",
        "MarathonPaceRunning",
        "ThresholdRunning",
        "IntervalTraining",
};
