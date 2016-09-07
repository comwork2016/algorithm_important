#include <iostream>
#include <list>
#include <vector>
#define NOTFOUND -1

using namespace std;

/*
在列表中寻找第一次出现10的位置和在此之前1出现的次数
*/
void findFirst01(int* flag,int length,int &pos10,int &count1)
{
    pos10 = NOTFOUND;
    count1 = 0;
    for(int i=0; i<length-1; i++)
    {
        if(flag[i]==1 && flag[i+1]==0)
        {
            pos10 = i;
            return;
        }
        if(flag[i] == 1)
        {
            count1++;
        }
    }
}

vector<list<char> > combination(vector<char> charvec,int num)
{
    vector<list<char> > combvec;
    int length = charvec.size();
    int flag[length];
    for(int i=0; i<length; i++)
    {
        if(i<num)
        {
            flag[i] = 1;
        }
        else
        {
            flag[i] = 0;
        }
    }
    list<char> charComb;
    for(int i=0; i<length; i++)
    {
        if(flag[i] == 1)
        {
            charComb.push_back(charvec[i]);
        }
    }
    combvec.push_back(charComb);
    int pos10 = NOTFOUND;
    int count1 = 0;
    findFirst01(flag,length,pos10,count1);
    while(pos10!=NOTFOUND)
    {
        // 将低位的 1 与相邻的高位的 0 交换位置。
        flag[pos10] = 0;
        flag[pos10+1] = 1;
        //同时，应该将比发生换位的 1 低位的所有的 1 挪到最低位。
        for(int i=0; i<pos10; i++)
        {
            if(i<count1)
            {
                flag[i] = 1;
            }
            else
            {
                flag[i] = 0;
            }
        }
        list<char> charComb1;
        for(int i=0; i<length; i++)
        {
            if(flag[i] == 1)
            {
                charComb1.push_back(charvec[i]);
            }
        }
        combvec.push_back(charComb1);
        findFirst01(flag,length,pos10,count1);
    }
    return combvec;
}

int main()
{
    vector<char> charlist;
    charlist.push_back('a');
    charlist.push_back('b');
    charlist.push_back('c');
    charlist.push_back('d');
    charlist.push_back('e');
    vector<list<char> > combvec = combination(charlist,3);
    for(int i=0; i<combvec.size(); i++)
    {
        list<char> comb = combvec[i];
        for(list<char>::iterator it = comb.begin(); it != comb.end();it++)
        {
            cout<<*it;
        }
        cout<<endl;
    }
}
