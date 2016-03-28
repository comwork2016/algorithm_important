/*
�ȶ����㷨
ʱ��Ч�ʣ�
    ���������Ϊn����¼��d���ؼ��룬�ؼ����ȡֵ��ΧΪradix��
    �������ʽ���������ʱ�临�Ӷ�ΪO(d(n+radix))��
    ���У�һ�˷���ʱ�临�Ӷ�ΪO(n)��һ���ռ�ʱ�临�Ӷ�ΪO(n)��������d�˷�����ռ���

�ռ�Ч�ʣ�
    ��Ҫ2*radix��ָ����еĸ����ռ䣬�Լ����ھ�̬�����n��ָ�롣

��Ҫ˼·��
    �����д��Ƚ���ֵ(ע��,������������)ͳһΪͬ������λ����,��λ�϶̵���ǰ�油��.
    Ȼ��, �����λ��ʼ, ���ν���һ���ȶ�����(���������㷨).
    ���������λ����һֱ�����λ��������Ժ�, ���оͱ��һ����������.

���Ҫ�Ӹ�λ����, ��ô�θ�λ�������Ӱ���λ�Ѿ��źõĴ�С��ϵ.
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
        for(int i=0; i<10; i++) //���Ͱ
        {
            bucket[i]=NULL;
        }
        for(int i=0; i<length; i++)
        {
            int n = num[i]/weight;//��Ҫȥ���Ź���ĵ�λ
            int b = n%10; //ĳһλ�ϵ�ֵ
            // add to bucket
            QNode* q = (QNode*)malloc(sizeof(QNode));
            q->value = num[i];
            q->next=NULL;
            QNode* p = bucket[b];
            //��ǰû����ӹ�
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
