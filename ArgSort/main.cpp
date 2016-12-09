#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

template<typename T>

vector<int> argsort(const vector<T>& a)
{
    int Len = a.size();
    vector<int> idx(Len, 0);
    for(int i = 0; i < Len; i++)
    {
        idx[i] = i;
    }
    sort(idx.begin(),idx.end(),[&a](int i1, int i2){return a[i1] < a[i2];});
    return idx;
}

int main()
{
    vector<int> vec;
    vec.push_back(2);
    vec.push_back(3);
    vec.push_back(1);
    vec.push_back(7);
    vec.push_back(4);
    vector<int> args = argsort(vec);
    for(int i:args)
    {
        cout<<i<<"("<<vec[i]<<")"<<endl;
    }
    return 0;
}
