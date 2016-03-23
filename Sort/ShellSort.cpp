/*
希尔排序
特点：unstable sort、In-place sort
最好情况：由于希尔排序的好坏和步长d的选择有很多关系.
最坏情况下：O(N*logN)，最坏的情况下和平均情况下差不多
平均情况下：O(N*logN)

思想：希尔排序也是一种插入排序方法,实际上是一种分组插入方法。
先取定一个小于n的整数d1作为第一个增量,把表的全部记录分成d1个组,所有距离为d1的倍数的记录放在同一个组中,在各组内进行直接插入排序；
然后,取第二个增量d2(＜d1),重复上述的分组和排序,直至所取的增量dt=1(dt<dt-1<…<d2<d1),即所有记录放在同一组中进行直接插入排序为止。
*/
void ShellInsert(int num[],int length,int delta);

void ShellSort(int num[], int length)
{
    //步长选择为n/2并且对步长取半直到步长达到 1
    int delta = length/2;
    while(delta>0)//最后一次的步长为1
    {
        ShellInsert(num,length,delta);
        delta = delta/2;
    }
}

//间隔一个步长的元素进行插入排序
void ShellInsert(int num[],int length,int delta)
{
    int i;
    for(i=delta; i<length; i++)
    {
        int key = num[i];
        int j = i - delta;
        while(j>=0 && num[j]>key)
        {
            num[j+delta] = num[j];
            j = j - delta;
        }
        num[j+delta] = key;
    }
}
