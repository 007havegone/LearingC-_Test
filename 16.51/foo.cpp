#include <iostream>
#include <string>
#include <sstream>
using namespace std;

//declaration
template<typename T> ostream& print(ostream& os, const T&t);
template<typename T, typename...Args> ostream& print(ostream& os, const T&t,const Args&...args);
template<typename T> string debug_rep(const T&);
template<typename T> string debug_rep(T*);

struct Node
{
	Node(int a = 15) :m_a(a) {}
	friend ostream& operator<<(ostream& os, const Node& n)
	{
		return os << n.m_a ;
	}
	int m_a;
};

template<typename T,typename... Args>
void foo(T &t, const Args&... args)
{
	cout << sizeof...(args) << " ";
	cout << sizeof...(args) << endl;
}

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

template<typename T>
ostream& print(ostream& os, const T&t)
{
	return os << t;
}

template<typename T,typename...Args>
ostream& print(ostream& os, const T&t1,const Args&...args)
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
	/*foo(i, s,42,d);
	foo(s, 42, "hi");
	foo(d, s);
	foo("hi");
	print(cout, "Hello", Node(16), i, d, s);*/

	errorMsg(cout, "Hello",45,i,d, s) << endl;
}

