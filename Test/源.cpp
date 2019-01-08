#include <iostream>
#include <vector>
#include <string>
#include <string>
using namespace std;

void f(int &a, int b)
{
	cout << ++a << " " << ++b << endl;
}
void g(int &&a, int &b)
{
	cout << ++a << " " << ++b << endl;
}
void h(int a, int b)
{
	cout << ++a << " " << ++b << endl;
}
void e(const int a, const int&b)
{
	cout << a << " " << b << endl;
}
template<typename F,typename T1,typename T2>
void funa(F f, T1 t1, T2 t2)
{
	f(t1, t2);
}
template<typename F,typename T1,typename T2>
void fun(F f, T1 &&t1, T2 &&t2)
{
	f(forward<T1>(t1), forward<T2>(t2));
}
template<typename T>
void func(T&& t)
{
}

template<typename T>
void func(const T&)
{

}
template<typename T>
typename remove_reference<T>::type&& M_move(T&& t)
{
	return static_cast<typename remove_reference<T>::type &&>(t);
}

int main()
{
	int a=10;
	int b=20;
	const int c = 15;

	cout << "h(int a,int b)" << endl;
	h(a, b);
	cout << a << " " << b << endl;
	cout << endl;
	fun(h, a, b);
	cout << a << " " << b << endl;

	cout << "\n" << "f(int &a,int b)" << endl;
	f(a, b);
	cout << a << " " << b << endl;
	cout << endl;
	fun(f, a, b);
	cout << a << " " << b << endl;

	cout << "\n" << "g(int &&a,int b)" << endl;
	g(42, b);
	cout << "42 " << b << endl;
	cout << endl;
	fun(g, 42, b);
	cout << "42 " << b << endl;
}