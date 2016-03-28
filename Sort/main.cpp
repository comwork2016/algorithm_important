#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <time.h>
#define LEN 20
#define MAX 100


void InsSort(int num[],int length);
void BubbleSort(int num[],int length);
void SelectSort(int num[],int length);
void MergeSort(int num[],int length);
void QuickSort(int num[],int length);
void HeapSort(int num[],int length);
void ShellSort(int num[], int length);
void CountSort(int num[],int length);
void RadixSort(int num[],int length);

int main()
{
    long dwStart,dwStop,runtime;
    //生成随机的数组用于排序
    int num[LEN],cpy[LEN],i; //num是用来排序的数组,cpy是用来保存随机数组
    srand((unsigned)time(NULL));
    printf("生成%d个随机数.\n排序前为:",LEN);
    for(i=0; i<LEN; i++)
    {
        num[i]=rand()%MAX;
        cpy[i] = num[i];
        printf("%d ",num[i]);
    }
    //插入排序
    dwStart=GetTickCount();
    InsSort(num,LEN);
    dwStop=GetTickCount();
    runtime=dwStop-dwStart;
    printf("\n\n插入排序:");
    for(i=0; i<LEN; i++)
    {
        printf("%d ",num[i]);
        num[i] = cpy[i];
    }
    printf("\n使用插入排序运行了%ldms\n",runtime);

    //冒泡排序
    dwStart=GetTickCount();
    BubbleSort(num,LEN);
    dwStop=GetTickCount();
    runtime=dwStop-dwStart;
    printf("\n冒泡排序:");
    for(i=0; i<LEN; i++)
    {
        printf("%d ",num[i]);
        num[i] = cpy[i];
    }
    printf("\n使用冒泡排序运行了%ldms\n",runtime);

    //选择排序
    dwStart=GetTickCount();
    SelectSort(num,LEN);
    dwStop=GetTickCount();
    runtime=dwStop-dwStart;
    printf("\n选择排序:");
    for(i=0; i<LEN; i++)
    {
        printf("%d ",num[i]);
        num[i] = cpy[i];
    }
    printf("\n使用选择排序运行了%ldms\n",runtime);

    //归并排序
    dwStart=GetTickCount();
    MergeSort(num,LEN);
    dwStop=GetTickCount();
    runtime=dwStop-dwStart;
    printf("\n归并排序:");
    for(i=0; i<LEN; i++)
    {
        printf("%d ",num[i]);
        num[i] = cpy[i];
    }
    printf("\n使用归并排序运行了%ldms\n",runtime);

    //快速排序
    dwStart=GetTickCount();
    QuickSort(num,LEN);
    dwStop=GetTickCount();
    runtime=dwStop-dwStart;
    printf("\n快速排序:");
    for(i=0; i<LEN; i++)
    {
        printf("%d ",num[i]);
        num[i] = cpy[i];
    }
    printf("\n使用快速排序运行了%ldms\n",runtime);

    //堆排序
    dwStart=GetTickCount();
    HeapSort(num,LEN);
    dwStop=GetTickCount();
    runtime=dwStop-dwStart;
    printf("\n堆排序:  ");
    for(i=0; i<LEN; i++)
    {
        printf("%d ",num[i]);
        num[i] = cpy[i];
    }
    printf("\n使用堆排序运行了%ldms\n",runtime);

    //希尔排序
    dwStart=GetTickCount();
    ShellSort(num,LEN);
    dwStop=GetTickCount();
    runtime=dwStop-dwStart;
    printf("\n希尔排序:");
    for(i=0; i<LEN; i++)
    {
        printf("%d ",num[i]);
        num[i] = cpy[i];
    }
    printf("\n使用希尔排序运行了%ldms\n",runtime);

    //计数排序
    dwStart=GetTickCount();
    CountSort(num,LEN);
    dwStop=GetTickCount();
    runtime=dwStop-dwStart;
    printf("\n计数排序:");
    for(i=0; i<LEN; i++)
    {
        printf("%d ",num[i]);
        num[i] = cpy[i];
    }
    printf("\n使用计数排序运行了%ldms\n",runtime);

    //基数排序
    dwStart=GetTickCount();
    RadixSort(num,LEN);
    dwStop=GetTickCount();
    runtime=dwStop-dwStart;
    printf("\n基数排序:");
    for(i=0; i<LEN; i++)
    {
        printf("%d ",num[i]);
        num[i] = cpy[i];
    }
    printf("\n使用基数排序运行了%ldms\n",runtime);

    return 1;
}
