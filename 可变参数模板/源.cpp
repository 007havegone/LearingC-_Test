#include <iostream>
using namespace std;

template<typename T>
void show(const T &t)
{
	cout << t << endl;

}
template<typename T,typename...Args>
void show(const T &t,const Args&...args)//使用参数包
{
	cout << t << " , ";
	show(args...);
}
int main()
{
	
	show(1, 2, 3, "123", "Jom", 12.0);
}