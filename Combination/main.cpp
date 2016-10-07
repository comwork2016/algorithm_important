#include <iostream>
#include <vector>

using namespace std;

void combine(char* pStr,int k,vector<char> result)
{
	if(k == 0)
	{
        for(vector<char>::iterator it = result.begin();it!=result.end();++it)
        {
            cout<<*it;
        }
        cout<<endl;
        return;
	}
	if(*pStr == '\0')
        return;
    result.push_back(*pStr);
    combine(pStr+1,k-1,result);
    result.pop_back();
    combine(pStr+1,k,result);
}

int main()
{
    char str[] = "abcd";
    vector<char> result;
    combine(str,3,result);
	return 0;
}
