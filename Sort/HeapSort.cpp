/*
堆排序
特性：unstable sort、In-place sort。
最优时间：O(nlgn)
最差时间：O(nlgn)

二叉堆的定义
二叉堆是完全二叉树或者是近似完全二叉树。
二叉堆满足二个特性：
1．父结点的键值总是大于或等于（小于或等于）任何一个子节点的键值。
2．每个结点的左子树和右子树都是一个二叉堆（都是最大堆或最小堆）。

堆的存储
一般都用数组来表示堆，i结点的父结点下标就为(i – 1) / 2。它的左右子结点下标分别为2 * i + 1和2 * i + 2。如第0个结点左右子结点下标分别为1和2。

其基本思想为(大顶堆)：
    1)将初始待排序关键字序列(R0,R1....Rn-1)构建成大顶堆，此堆为初始的无序区；
    2)将堆顶元素R[0]与最后一个元素R[n-1]交换，此时得到新的无序区(R0,R2,......Rn-2)和新的有序区(Rn-1),且满足R[0,1,2...n-2]<=R[n-1];
    3)由于交换后新的堆顶R[0]可能违反堆的性质，因此需要对当前无序区(R0,R1,......Rn-2)调整为新堆，
    然后再次将R[0]与无序区最后一个元素交换，得到新的无序区(R0,R1....Rn-3)和新的有序区(Rn-2,Rn-1)。
    不断重复此过程直到有序区的元素个数为n-1，则整个排序过程完成。
*/

void BigHeap(int num[], int right);

void HeapSort(int num[],int length)
{
    BigHeap(num,length-1);
    for (int i=length-1; i>=1; i--)
    {
        //将第一个元素与最后一个元素交换
        int tmp = num[0];
        num[0] = num[i];
        num[i] = tmp;
        BigHeap(num,i-1);
    }
}

//将数组[0:right]调整为大顶堆
void BigHeap(int num[], int right)
{
    if(right==0)//堆只剩一个元素时,不需要调整
    {
        return;
    }
    //从堆中的最后一个非叶子结点((right-1)/2)遍历
    for (int i=(right-1)/2; i>=0; i--)
    {
        int maxnode = i;//记录最大的节点
        //左孩子
        int leftchild = i*2+1;
        if(num[leftchild] > num[maxnode]) //左孩子大于父节点
        {
            maxnode = leftchild;
        }
        //右孩子
        int rightchild = i*2+2;
        if(rightchild <= right) //右孩子存在
        {
            if(num[rightchild] > num[maxnode]) //右孩子大于父节点,交换
            {
                maxnode = rightchild;
            }
        }
        if(maxnode != i)//父节点不是最大值,交换
        {
            int tmp = num[i];
            num[i] = num[maxnode];
            num[maxnode] = tmp;
            //交换之后如果上部分堆不是大顶堆,则需要继续交换
            BigHeap(num,maxnode);
        }
    }
}
