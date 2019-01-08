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
string debug_rep(const T& t)//ģ��1��������������
{
	ostringstream ret;
	ret << t;
	return ret.str();
}
template<typename T>
string debug_rep(T* t)//ģ��2����ָ�����͸�����
{
	ostringstream ret;
	ret << "pointer: " << t;//Ҫ��ӡ��ַ��char*������Ҫ����ʵ����
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
//���غ�������ı�ƥ�䣬δ���ʱconst char*��char*��ģ��2ƥ��
//��Ӻ���Ϊʱ��ģ�������ѡ��ƥ��
//string debug_rep(const char* p)
//{
//	return debug_rep(string(p));//ƥ��ģ��1
//}
//string debug_rep(char *p)
//{
//	return debug_rep(string(p));//ƥ��ģ��1
//}
/*------------------------------------------------------------*/

/*------------------------------------------------------------*/
//������ģ��
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

