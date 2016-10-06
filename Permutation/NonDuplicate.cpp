#include <iostream>

using namespace std;

void swap(char* pStr,char* pBegin);

bool isSwap(char* pBegin,char* pEnd)
{
    for(char* p = pBegin; p<pEnd; p++)
    {
        if(*p == *pEnd)
            return false;
    }
    return true;
}

void permutationNoDuplicate(char* pStr,char* pBegin)
{
    if(*pStr == '\0')
        return;
    if(*pBegin == '\0')
        cout<<pStr<<endl;
    else
    {
        for(char* pCh = pBegin; *pCh!='\0'; pCh++)
        {
            if(isSwap(pBegin,pCh))
            {
                swap(pBegin,pCh);
                permutationNoDuplicate(pStr,pBegin+1);
                swap(pBegin,pCh);
            }
        }
    }
}
