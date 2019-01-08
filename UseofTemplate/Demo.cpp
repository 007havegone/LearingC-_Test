#include <iostream>
#include <string>
#include "template.h"

using namespace std;

//declaration，not definition,模板声明，非定义
template<typename T> ostream& print(ostream&, const T&);
template<typename T> ostream& print(ostream&, T*);
template<typename T> class Node;
template<typename T> void Fun(const T&);

//explicit instantiation 显示实例声明，需要在别处定义
//减少生成多余的实例，引用别处生成的实例
extern template class Node<string>;
extern template void Fun(const int&t);

//specific the template 2 print(ostream&,T*),模板特例化,具体化（区别于原模板操作）必须有定义
//下面声明等价
template<> ostream& print<const char>(ostream& os, const char*t)
//template<> ostream& print(ostream& os, const char*t)
{
	return	print(os,string(t));
}


int main()
{
	string str("Hello");
	const string cstr("World");
	char carr[] = "Good";
	const char* pc = "Great";
	int i = 1;
	const int*ci = &i;
	double d = 16.1;
	print(cout,i);
	print(cout, ci);
	print(cout, "Helo");
	print(cout, 16);
	print<const char>(cout, "world");
	Fun(i);
	Fun(carr);
	Node<int> n(100);
	Node<string> sn("Hello");
	cout << n << endl;
	cout << sn << endl;
	Fun(16);
}


