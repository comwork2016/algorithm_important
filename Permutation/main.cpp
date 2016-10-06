#include <iostream>

using namespace std;

void swap(char* pStr,char* pBegin);
void permutationDuplicate(char* pStr,char* pBegin);

bool isSwap(char* pBegin,char* pEnd);
void permutationNoDuplicate(char* pStr,char* pBegin);

void permutationNoRecursion(char* pStr);

int main()
{
    char pStr[] = "baa";
    permutationDuplicate(pStr,pStr);
    cout<<"-----------------------"<<endl;
    permutationNoDuplicate(pStr,pStr);
    cout<<"-----------------------"<<endl;
    permutationNoRecursion(pStr);
    return 0;
}
