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
    //���������������������
    int num[LEN],cpy[LEN],i; //num���������������,cpy�����������������
    srand((unsigned)time(NULL));
    printf("����%d�������.\n����ǰΪ:",LEN);
    for(i=0; i<LEN; i++)
    {
        num[i]=rand()%MAX;
        cpy[i] = num[i];
        printf("%d ",num[i]);
    }
    //��������
    dwStart=GetTickCount();
    InsSort(num,LEN);
    dwStop=GetTickCount();
    runtime=dwStop-dwStart;
    printf("\n\n��������:");
    for(i=0; i<LEN; i++)
    {
        printf("%d ",num[i]);
        num[i] = cpy[i];
    }
    printf("\nʹ�ò�������������%ldms\n",runtime);

    //ð������
    dwStart=GetTickCount();
    BubbleSort(num,LEN);
    dwStop=GetTickCount();
    runtime=dwStop-dwStart;
    printf("\nð������:");
    for(i=0; i<LEN; i++)
    {
        printf("%d ",num[i]);
        num[i] = cpy[i];
    }
    printf("\nʹ��ð������������%ldms\n",runtime);

    //ѡ������
    dwStart=GetTickCount();
    SelectSort(num,LEN);
    dwStop=GetTickCount();
    runtime=dwStop-dwStart;
    printf("\nѡ������:");
    for(i=0; i<LEN; i++)
    {
        printf("%d ",num[i]);
        num[i] = cpy[i];
    }
    printf("\nʹ��ѡ������������%ldms\n",runtime);

    //�鲢����
    dwStart=GetTickCount();
    MergeSort(num,LEN);
    dwStop=GetTickCount();
    runtime=dwStop-dwStart;
    printf("\n�鲢����:");
    for(i=0; i<LEN; i++)
    {
        printf("%d ",num[i]);
        num[i] = cpy[i];
    }
    printf("\nʹ�ù鲢����������%ldms\n",runtime);

    //��������
    dwStart=GetTickCount();
    QuickSort(num,LEN);
    dwStop=GetTickCount();
    runtime=dwStop-dwStart;
    printf("\n��������:");
    for(i=0; i<LEN; i++)
    {
        printf("%d ",num[i]);
        num[i] = cpy[i];
    }
    printf("\nʹ�ÿ�������������%ldms\n",runtime);

    //������
    dwStart=GetTickCount();
    HeapSort(num,LEN);
    dwStop=GetTickCount();
    runtime=dwStop-dwStart;
    printf("\n������:  ");
    for(i=0; i<LEN; i++)
    {
        printf("%d ",num[i]);
        num[i] = cpy[i];
    }
    printf("\nʹ�ö�����������%ldms\n",runtime);

    //ϣ������
    dwStart=GetTickCount();
    ShellSort(num,LEN);
    dwStop=GetTickCount();
    runtime=dwStop-dwStart;
    printf("\nϣ������:");
    for(i=0; i<LEN; i++)
    {
        printf("%d ",num[i]);
        num[i] = cpy[i];
    }
    printf("\nʹ��ϣ������������%ldms\n",runtime);

    //��������
    dwStart=GetTickCount();
    CountSort(num,LEN);
    dwStop=GetTickCount();
    runtime=dwStop-dwStart;
    printf("\n��������:");
    for(i=0; i<LEN; i++)
    {
        printf("%d ",num[i]);
        num[i] = cpy[i];
    }
    printf("\nʹ�ü�������������%ldms\n",runtime);

    //��������
    dwStart=GetTickCount();
    RadixSort(num,LEN);
    dwStop=GetTickCount();
    runtime=dwStop-dwStart;
    printf("\n��������:");
    for(i=0; i<LEN; i++)
    {
        printf("%d ",num[i]);
        num[i] = cpy[i];
    }
    printf("\nʹ�û�������������%ldms\n",runtime);

    return 1;
}
