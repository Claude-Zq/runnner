#include <stdio.h>
#include"fileManager.h"
#include "api.h"

int main() {

    InitRecordsArray(); //将文件中的数据加载到内存中
    while (1){
        ShowMenu();
        printf("请输入您的选择:");

        int select,ignore;
        while (scanf("%d",&select)!= 1){
            printf("输入错误请重新输入:");
            while ((ignore = getchar()) != '\n');//清空输入缓冲区用scanf(“%*[^\n]%*c”)会遗留回车符
        }
        while ((ignore = getchar()) != '\n');//清空输入缓冲区

        switch (select)
        {
            case 0://退出程序
                printf("欢迎下次使用\n");
                return 0;
            case 1://添加记录
                AddRecord();
                printf("按任意键继续");
                getchar();
                system("clear");
                break;
            case 2://删除记录
                DeleteRecord();
                printf("按任意键继续");
                getchar();
                system("clear");
                break;
            case 3:
                SelectRecords();
                printf("按任意键继续");
                getchar();
                system("clear");
                break;
            case 4:
                AnalyzeRecord();
                printf("按任意键继续");
                getchar();
                system("clear");
                break;

            default:
                printf("无该选项！");
                getchar();//按任意键后清屏
                system("clear");//清屏windows用cls
                break;
        }

    }


}
