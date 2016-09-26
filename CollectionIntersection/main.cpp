#include <iostream>

using std::cout;
using std::cin;
using std::endl;

int main()
{
    //定义两个数组
    int array1[] = {7,1,2,5,4,3,5,6,3,4,5,6,7,3,2,5,6,6};
    int size1 = sizeof(array1) / sizeof(array1[0]);
    int array2[] = {8,2,1,3,4,5,3,2,4,5,3,2,1,3,5,4,6,9};
    int size2 = sizeof(array2) / sizeof(array2[0]);;
    int end = size1;

    bool swap = false;//标识变量，表示两种情况中的哪一种

    for(int i=0;i<end;i++)
    {
        swap = false;//开始假设是第一种情况
        for(int j=i ; j < size2; j++)//找到与该元素存在相同的元素，将这个相同的元素交换到与该元素相同下标的位置上
        {
            if(array1[i] == array2[j])//第二种情况，找到了相等的元素
            {
                int tmp = array2[i];//对数组2进行交换
                array2[i] = array2[j];
                array2[j] = tmp;
                swap = true;//设置标志
                break;
            }
        }
        if(swap != true)//第一种情况，没有相同元素存在时，将这个元素交换到尚未进行比较的尾部
        {
            int tmp = array1[i];
            array1[i] = array1[--end];
            array1[end] = tmp;
            i--;
        }
    }
    //结果就是在end表示之前的元素都找到了匹配，而end元素之后的元素都未被匹配

    //先输出array
    cout<<"array1:";
    for(int i = 0 ; i < size1; i++)
    {
        cout<<array1[i]<<" ";
    }
    cout<<endl;
    cout<<"array2:";
    for(int i = 0 ; i < size2; i++)
    {
        cout<<array2[i]<<" ";
    }
    cout<<endl;

    //先输出差集
    cout<<"only in array1"<<endl;
    for(int i = end ; i < size1; i++)
    {
        cout<<array1[i]<<" ";
    }
    cout<<endl;
    cout<<"only in array2"<<endl;
    for(int i = end ; i < size2; i++)
    {
        cout<<array2[i]<<" ";
    }
    cout<<endl;
    //输出交集
    cout<<"elements in array1 and array2"<<endl;
    for(int i = 0 ; i <end ; i++)
    {
        cout<<array1[i]<<" ";
    }
    cout<<endl;
    //输出并集
    cout<<"elements in array1 or array2"<<endl;
    for(int i = 0 ; i <end ; i++)
    {
        cout<<array1[i]<<" ";
    }
    for(int i = end ; i < size1; i++)
    {
        cout<<array1[i]<<" ";
    }
    for(int i = end ; i < size2; i++)
    {
        cout<<array2[i]<<" ";
    }
    cout<<endl;

}
