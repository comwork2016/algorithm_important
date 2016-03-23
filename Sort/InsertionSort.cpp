/*
插入排序:
特点：stable sort、In-place sort
最优复杂度：当输入数组就是排好序的时候，复杂度为O(n)，而快速排序在这种情况下会产生O(n^2)的复杂度。
最差复杂度：当输入数组为倒序时，复杂度为O(n^2)
插入排序比较适合用于“少量元素的数组”。
*/

void InsSort(int num[],int length)
{
    int key,i,j;
    for (i=1; i<length; i++)
    {
        key = num[i];
        j=i-1;
        while(j>=0 && key<num[j])
        {
            num[j+1]=num[j];
            j--;
        }
        num[j+1]=key;
    }
}
