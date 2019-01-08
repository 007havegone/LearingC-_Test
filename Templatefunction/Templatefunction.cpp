#include <iostream>
using std::cout;
using std::endl;
template <typename T>
void Add(T t1, T t2);
template <> void Add<char>(char c1, char c2);
template void Add<long>(long t1, long t2);
int main()
{
	int a=11, b=12;
	double c=1.1, d=2.2;
	char e = 'a', f = 'b';
	long g = 100000, h = 23333333;
	Add(a, b);
	Add(c, d);
	Add(e, f);
	Add(g, h);
	Add<double>(a, c);//œ‘ æ
	Add<int>(a, c);
	return 0;
}
template <typename T>
void Add(T t1, T t2)
{
	cout << "t1 + t2 = " << t1 + t2 << endl;
}
template<> void Add(char c1, char c2)
{
	cout << c1 << "," << c2 << endl;
}