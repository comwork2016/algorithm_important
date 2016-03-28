/*
计数排序
特性：stable sort、out-place sort。
最坏情况运行时间：O(n+k)
最好情况运行时间：O(n+k)

初始化一个计数数组，大小是输入数组中的最大的数。
遍历输入数组，遇到一个数就在计数数组对应的位置上加一。例如：遇到5，就将计数数组第五个位置的数加一。
把计数数组直接覆盖到输出数组（节约空间）。
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void CountSort(int num[],int length)
{
    int max = num[0];
    int *countArr = (int*)malloc(sizeof(int)*(max+1));
    // 初始化数组
    for(int i=0; i<max+1; i++)
    {
        countArr[i] = 0;
    }
    for(int i=0; i<length; i++)
    {
        if(max<num[i])
        {
            int oldmax = max;
            max = num[i];
            countArr = (int*)realloc(countArr,sizeof(int)*(max+1));
            for(int j=oldmax+1; j<max+1; j++)
            {
                countArr[j] = 0;
            }
        }
        countArr[num[i]]++;
    }
    int k=0;
    for(int i=0;i<max+1;i++)
    {
        int count = countArr[i];
        while(count>0)
        {
            num[k] = i;
            count--;
            k++;
        }
    }
}
