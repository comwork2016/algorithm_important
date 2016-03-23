/*
特点：stable sort、In-place sort
思想：通过两两交换，像水中的泡泡一样，小的先冒出来，大的后冒出来。
最坏运行时间：O(n^2)
最佳运行时间：O(n^2)（改进后使得最佳运行时间为O(n)）
*/

void BubbleSort(int num[],int length)
{
    int i,j,temp;
    bool flag = true;
    for(i=length-1; i>=0; i--)
    {
        if(flag == false)
        {
            return;
        }
        for(j=0; j<i; j++)
        {
            if(num[j]>num[j+1])
            {
                temp=num[j];
                num[j]=num[j+1];
                num[j+1]=temp;
                flag = true;
            }
        }
    }
}
