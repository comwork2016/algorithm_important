#include <iostream>

using namespace std;

void swap(char* pStr,char* pBegin)
{
    char c = *pStr;
    *pStr = *pBegin;
    *pBegin = c;
}

void permutationDuplicate(char* pStr,char* pBegin)
{
    if(*pStr == '\0')
        return;
    if(*pBegin == '\0')
        cout<<pStr<<endl;
    else
    {
        for(char* pCh = pBegin;*pCh!='\0';pCh++)
        {
            swap(pBegin,pCh);
            permutationDuplicate(pStr,pBegin+1);
            swap(pBegin,pCh);
        }
    }
}
