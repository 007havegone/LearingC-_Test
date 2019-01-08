#include <iostream>
#include <string>
#include <sstream>
using namespace std;

template<typename T> string debug_rep(const T&);
template<typename T> string debug_rep(T*);

template<typename T>
string debug_rep(const T& t)//������������
{
	ostringstream ret;
	ret << t;
	return ret.str();
}
template<typename T>
string debug_rep(T* t)//��ָ�����͸�����
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
string debug_rep(const char* p)
{
	return debug_rep(string(p));//ƥ��ģ��1
}
string debug_rep(char *p)
{
	return debug_rep(string(p));//ƥ��ģ��1
}
int main()
{
	char str[] = "Hello world";
	string s("hi");
	cout << debug_rep(s) << endl;
	cout << debug_rep(&s) << endl;
	cout << debug_rep("hi world") << endl;//û����ͨ��������ڶ���ģ��ƥ��
	cout << debug_rep(str) << endl;
}
