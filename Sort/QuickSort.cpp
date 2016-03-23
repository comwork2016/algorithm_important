/*
快速排序
特性：unstable sort、In-place sort。
最坏运行时间：当输入数组已排序时，时间为O(n^2)，当然可以通过随机化来改进（shuffle array 或者 randomized select pivot）,使得期望运行时间为O(nlgn)。
最佳运行时间：O(nlgn)
快速排序的思想也是分治法。

在理想状况下，每一次都将待排序数组划分成等长两个部分，则需要logn次划分。
而在最坏情况下，即数组已经有序或大致有序的情况下，每次划分只能减少一个元素，快速排序将不幸退化为冒泡排序，所以快速排序时间复杂度下界为O(nlogn)，最坏情况为O(n^2)。
*/

void qsort(int num[],int left,int right);
int partition(int num[],int left,int right);

void QuickSort(int num[],int length)
{
    qsort(num,0,length-1);
}

void qsort(int num[],int left,int right)
{
    if(left < right)
    {
        int pos = partition(num,left,right);
        qsort(num,left,pos-1);
        qsort(num,pos+1,right);
    }
}

int partition(int num[],int left,int right)
{
    int pivot = num[left];
    int i,j;
    i = left;
    j = right;
    while(i<j)
    {
        while(i<j && num[j]>=pivot)
        {
            j--;
        }
        if(i<j)
        {
            num[i] = num[j];
            i++;
        }
        while(i<j && num[i] < pivot)
        {
            i++;
        }
        if(i<j)
        {
            num[j] = num[i];
            j--;
        }
    }
    num[i] = pivot;
    return i;
}
