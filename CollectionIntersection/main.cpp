#include <iostream>

using std::cout;
using std::cin;
using std::endl;

int main()
{
    //������������
    int array1[] = {7,1,2,5,4,3,5,6,3,4,5,6,7,3,2,5,6,6};
    int size1 = sizeof(array1) / sizeof(array1[0]);
    int array2[] = {8,2,1,3,4,5,3,2,4,5,3,2,1,3,5,4,6,9};
    int size2 = sizeof(array2) / sizeof(array2[0]);;
    int end = size1;

    bool swap = false;//��ʶ��������ʾ��������е���һ��

    for(int i=0;i<end;i++)
    {
        swap = false;//��ʼ�����ǵ�һ�����
        for(int j=i ; j < size2; j++)//�ҵ����Ԫ�ش�����ͬ��Ԫ�أ��������ͬ��Ԫ�ؽ��������Ԫ����ͬ�±��λ����
        {
            if(array1[i] == array2[j])//�ڶ���������ҵ�����ȵ�Ԫ��
            {
                int tmp = array2[i];//������2���н���
                array2[i] = array2[j];
                array2[j] = tmp;
                swap = true;//���ñ�־
                break;
            }
        }
        if(swap != true)//��һ�������û����ͬԪ�ش���ʱ�������Ԫ�ؽ�������δ���бȽϵ�β��
        {
            int tmp = array1[i];
            array1[i] = array1[--end];
            array1[end] = tmp;
            i--;
        }
    }
    //���������end��ʾ֮ǰ��Ԫ�ض��ҵ���ƥ�䣬��endԪ��֮���Ԫ�ض�δ��ƥ��

    //�����array
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

    //������
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
    //�������
    cout<<"elements in array1 and array2"<<endl;
    for(int i = 0 ; i <end ; i++)
    {
        cout<<array1[i]<<" ";
    }
    cout<<endl;
    //�������
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
