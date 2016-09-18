#include <iostream>
#include <string>
#include <sstream>

using namespace std;

int main()
{
    string str = "2,3,4,5";
    stringstream ss(str);
    string tmp;
    char delm = ',';
    while(getline(ss,tmp,delm))
    {
        cout<<tmp<<endl;
    }
    return 0;
}
