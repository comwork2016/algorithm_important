/*
稳定的算法
时间效率：
    设待排序列为n个记录，d个关键码，关键码的取值范围为radix，
    则进行链式基数排序的时间复杂度为O(d(n+radix))，
    其中，一趟分配时间复杂度为O(n)，一趟收集时间复杂度为O(n)，共进行d趟分配和收集。

空间效率：
    需要2*radix个指向队列的辅助空间，以及用于静态链表的n个指针。

主要思路：
    将所有待比较数值(注意,必须是正整数)统一为同样的数位长度,数位较短的数前面补零.
    然后, 从最低位开始, 依次进行一次稳定排序(计数排序算法).
    这样从最低位排序一直到最高位排序完成以后, 数列就变成一个有序序列.

如果要从高位排序, 那么次高位的排序会影响高位已经排好的大小关系.
*/

#include <iostream>
#include <stdlib.h>


struct QNode
{
    int value;
    QNode *next;
};

void RadixSort(int num[],int length)
{
    QNode* bucket[10];
    int weight = 1;
    int max = num[0];
    for(int i=0; i<length; i++)
    {
        if(max<num[i])
        {
            max = num[i];
        }
    }
    while(max /weight!=0)
    {
        for(int i=0; i<10; i++) //清空桶
        {
            bucket[i]=NULL;
        }
        for(int i=0; i<length; i++)
        {
            int n = num[i]/weight;//先要去掉排过序的低位
            int b = n%10; //某一位上的值
            // add to bucket
            QNode* q = (QNode*)malloc(sizeof(QNode));
            q->value = num[i];
            q->next=NULL;
            QNode* p = bucket[b];
            //以前没有添加过
            if(!p)
            {
                bucket[b] = q;
            }
            else
            {
                while(p->next)
                {
                    p =p->next;
                }
                p->next = q;
            }
        }
        int k=0;
        for(int i=0;i<10;i++)
        {
            QNode* p = bucket[i];
            while(p)
            {
                num[k]=p->value;
                k++;
                p=p->next;
            }
        }
        weight = weight * 10;
    }
}
