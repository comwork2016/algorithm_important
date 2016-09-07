#include <iostream>
#include <string>
#include <list>

using namespace std;

/*
    str: string to be splited
    delims: split separator
    return splited list
*/
list<string> splitString(const string strSource, const string strDelims)
{
    string delims = strDelims;
    string str;
    list<string> strSplited;
    if(delims.empty())
    {
        delims = "/n/r";
    }
    string::size_type pos=0, length = strSource.size();
    while(pos < length )
    {
        str="";
        //posָ����һ������delims�е��ַ���λ��
        while( (delims.find(strSource[pos]) != string::npos) && (pos < length) )
        {
            ++pos;
        }
        if(pos==length)
        {
            return strSplited;
        }
        //posָ����һ����delims�е��ַ���λ��
        while( (delims.find(strSource[pos]) == string::npos) && (pos < length) )
        {
            str += strSource[pos++];
        }
        if(!str.empty() )
        {
            strSplited.push_back(str);
        }
    }
    return strSplited;
}

int main()
{
    string str = "����ʱ��3��29��20:15���й�����������ӭս�������ӡ�ƾ��Ʋ��ĺ��������°�ʱ�Ľ����й���2-0��ʤ�������ӣ�����Լ���Ӻͳ��ʶӷֱ�渺���������������";
    string delims="������";
    list<string> strSplited = splitString(str,delims); //�����Զ���ķָ��
    for(list<string>::iterator it = strSplited.begin();it!=strSplited.end();it++)
    {
        cout<<*it<<endl;
    }

}
