/*
特性：In-place sort，stable sort。
思想：每次找一个最小值。
最好情况时间：O(n^2)。
最坏情况时间：O(n^2)。
*/
void SelectSort(int num[],int length)
{
    int i,j,min;
    for (i=0; i<length; i++)
    {
        min = i;
        for(j=i+1; j<length; j++)
        {
            if(num[j]<num[min])
            {
                min=j;
            }
        }
        if( min!=i)
        {
            int temp;
            temp = num[min];
            num[min] = num[i];
            num[i] = temp;
        }
    }

}
