#include <iostream>
#include <string>
using namespace std;

#define tab "\t"

int main()
{
	//为了保证本地化输出（文字/时间/货币等），chs表示中国，wcout必须使用本地化解析编码
	ios::sync_with_stdio(false);
	wcout.imbue(std::locale(""));

	//string 英文，正确颠倒位置，显示第二个字符正确
	string str1("ABCabc");
	string str11(str1.rbegin(),str1.rend());
	cout<<"UK\ts1\t:"<<str1<<tab<<str1[1]<<tab<<str11<<endl;

	//wstring 英文，正确颠倒位置，显示第二个字符正确
	wstring str2=L"ABCabc";
	wstring str22(str2.rbegin(),str2.rend());
	wcout<<"UK\tws4\t:"<<str2<<tab<<str2[1]<<tab<<str22<<endl;

	//string 中文，颠倒后，变成乱码，第二个字符读取也错误
	string str3("你好么？");
	string str33(str3.rbegin(),str3.rend());
	cout<<"CHN\ts3\t:"<<str3<<tab<<str3[1]<<tab<<str33<<endl;

	//正确的打印第二个字符的方法
	cout<<"CHN\ts3\t:RIGHT\t"<<str3[3]<<str3[4]<<str3[5]<<endl;

	//中文，正确颠倒位置，显示第二个字符正确
	wstring str4=L"你好么？";
	wstring str44(str4.rbegin(),str4.rend());
	wcout<<"CHN\tws4\t:"<<str4<<tab<<str4[1]<<tab<<str44<<endl;

	return 0;
}
