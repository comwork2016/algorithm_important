#include <string.h>
#include <iostream>
#include <algorithm>

using namespace std;

void swap(char* pStr,char* pBegin);

void Reverse(char* pBegin,char* pEnd)
{
    while(pBegin < pEnd)
        swap(pBegin++,pEnd--);
}

bool nextPermutation(char* pStr)
{
    if(pStr == nullptr)
        return false;
    char *p,*q,*pFind;
    char* pEnd = pStr + strlen(pStr) - 1;
    if(pEnd == pStr)
        return false;
    p = pEnd;
    while(p != pStr)
    {
        q = p;
        p--;
        if(*p < *q)
        {
            pFind = pEnd;
            while(*pFind <= *p)
                --pFind;
            swap(p,pFind);
            Reverse(q,pEnd);
            return true;
        }
    }
    Reverse(pStr,pEnd);
    return false;
}

int cmp(const void* a,const void* b)
{
    return int(*(char*)a - *(char*)b);
}

void permutationNoRecursion(char* pStr)
{
    int num = 1;
    qsort(pStr , strlen(pStr),sizeof(char),cmp);
    do
    {
        cout<<"µÚ"<<num++<<"¸öÅÅÁÐ\t"<<pStr<<endl;
    }while(nextPermutation(pStr));
}
