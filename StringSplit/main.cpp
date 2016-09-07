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
        //pos指到第一个不是delims中的字符的位置
        while( (delims.find(strSource[pos]) != string::npos) && (pos < length) )
        {
            ++pos;
        }
        if(pos==length)
        {
            return strSplited;
        }
        //pos指到下一个是delims中的字符的位置
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
    string str = "北京时间3月29日20:15，中国男足在西安迎战卡塔尔队。凭借黄博文和武磊在下半时的进球，中国队2-0完胜卡塔尔队！由于约旦队和朝鲜队分别告负，国足晋级在望！";
    string delims="，。！";
    list<string> strSplited = splitString(str,delims); //调用自定义的分割函数
    for(list<string>::iterator it = strSplited.begin();it!=strSplited.end();it++)
    {
        cout<<*it<<endl;
    }

}
