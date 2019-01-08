#include <iostream>
#include <string>
#include <sstream>
using namespace std;

template<typename T> string debug_rep(const T&);
template<typename T> string debug_rep(T*);

template<typename T>
string debug_rep(const T& t)//符合所有类型
{
	ostringstream ret;
	ret << t;
	return ret.str();
}
template<typename T>
string debug_rep(T* t)//对指针类型更具体
{
	ostringstream ret;
	ret << "pointer: " << t;//要打印地址，char*不符合要另外实例化
	if (t)
		ret << " " << debug_rep(*t);
	else
		ret << " null pointer";
	return ret.str();
}

string debug_rep(const string& s)
{
	return '"' + s + '"';
}
string debug_rep(const char* p)
{
	return debug_rep(string(p));//匹配模板1
}
string debug_rep(char *p)
{
	return debug_rep(string(p));//匹配模板1
}
int main()
{
	char str[] = "Hello world";
	string s("hi");
	cout << debug_rep(s) << endl;
	cout << debug_rep(&s) << endl;
	cout << debug_rep("hi world") << endl;//没有普通函数则与第二个模板匹配
	cout << debug_rep(str) << endl;
}
