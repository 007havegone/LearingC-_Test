#include <iostream>
#include <string>
#include <sstream>
using namespace std;

//declaration
template<typename T> ostream& print(ostream& os, const T&t);
template<typename T, typename...Args> ostream& print(ostream& os, const T&t, const Args&...args);
template<typename T> string debug_rep(const T&);
template<typename T> string debug_rep(T*);

struct Node
{
	Node(int a = 15) :m_a(a) {}
	friend ostream& operator<<(ostream& os, const Node& n)
	{
		return os << n.m_a;
	}
	int m_a;
};

template<typename T, typename... Args>
void foo(T &t, const Args&... args)
{
	cout << sizeof...(args) << " ";
	cout << sizeof...(args) << endl;
}

template<typename T>
string debug_rep(const T& t)//模板1，符合所有类型
{
	ostringstream ret;
	ret << t;
	return ret.str();
}
template<typename T>
string debug_rep(T* t)//模板2，对指针类型更具体
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
/*------------------------------------------------------------*/
//重载函数，会改变匹配，未添加时const char*和char*与模板2匹配
//添加后因为时非模板会优先选择匹配
//string debug_rep(const char* p)
//{
//	return debug_rep(string(p));//匹配模板1
//}
//string debug_rep(char *p)
//{
//	return debug_rep(string(p));//匹配模板1
//}
/*------------------------------------------------------------*/

/*------------------------------------------------------------*/
//特例化模板
//template<> string debug_rep(const char*p)
//{
//	return debug_rep(string(p));
//}
//template<> string debug_rep(char *p)
//{
//	return debug_rep(string(p));
//}
/*------------------------------------------------------------*/

template<typename T>
ostream& print(ostream& os, const T&t)
{
	return os << t;
}

template<typename T, typename...Args>
ostream& print(ostream& os, const T&t1, const Args&...args)
{
	os << t1 << " ";
	return print(os, args...);
}

template<typename...Args>
ostream &errorMsg(ostream& os, const Args&...args)
{
	return print(os, debug_rep(args)...);
}

int main()
{
	int i = 0;
	double d = 3.14;
	string s = "how now brown cow";
	char str[] = "World";
	const char *ps = "Hi";
	cout << debug_rep("hello") << endl;
	cout << debug_rep(s) << endl;
	cout << debug_rep(str) << endl;
	cout << debug_rep(ps) << endl;
	errorMsg(cout, "Hello", 45, i, d, s) << endl;
}

