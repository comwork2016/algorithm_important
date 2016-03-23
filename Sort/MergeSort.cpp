/*
特点：stable sort、Out-place sort
思想：运用分治法思想解决排序问题。
最坏情况运行时间：O(nlgn)
最佳运行时间：O(nlgn)

对于归并排序,当数组较小时,所用的时间比其他的排序方法花费的时间大,而
*/

#include <stdlib.h>

void msort(int num[],int left,int right);
void merge(int num[],int left,int center,int right);

void MergeSort(int num[],int length)
{
    msort(num,0,length-1);
}

void msort(int num[],int left,int right)
{
    int center;
    if(left<right)
    {
        center=(left+right)/2;
        msort(num,left,center);
        msort(num,center+1,right);
        merge(num,left,center,right);
    }
}

// center属于左边的待归并数组
void merge(int num[],int left,int center,int right)
{
    int lenL = center-left+1;
    int lenR = right-center;
    int* numL = (int*)malloc(sizeof(int)*lenL);
    int* numR = (int*)malloc(sizeof(int)*lenR);
    int i,j;
    for(i=0;i<lenL;i++)
    {
        numL[i] = num[left+i];
    }
    for(j=0;j<lenR;j++)
    {
        numR[j] = num[center+1+j];
    }
    i = 0;
    j = 0;
    int k;
    for(k=left; k<=right && i<lenL && j<lenR;k++)
    {
        if(numL[i] <= numR[j])
        {
            num[k] = numL[i];
            i++;
        }
        else
        {
            num[k] = numR[j];
            j++;
        }
    }
    if(i<lenL)
    {
        while(i<lenL)
        {
            num[k] = numL[i];
            k++;
            i++;
        }
    }
    if(j<lenR)
    {
        while(j<lenR)
        {
            num[k] = numR[j];
            k++;
            j++;
        }
    }
}
