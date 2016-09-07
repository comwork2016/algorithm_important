#include <iostream>
#include <fstream>
#include <sstream>


using namespace std;

int main()
{
    ios::sync_with_stdio(false);
	wcout.imbue(locale(""));
    wifstream wifs_Doc;
    wifs_Doc.imbue(locale(""));
    wifs_Doc.open("test.txt");
    if(!wifs_Doc.is_open())
    {
        cout<<"read file error"<<endl;
        return -1;
    }
    wstringstream wss;
    wss << wifs_Doc.rdbuf();
    wstring wstr_Contents = wss.str();
    for(int i=0;i<wstr_Contents.length();i++)
    {
        wcout<<i<<"---"<<wstr_Contents.at(i)<<endl;
    }
    return 0;
}
