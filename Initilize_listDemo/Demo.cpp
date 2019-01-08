#include <iostream>
#include <string>
#include <initializer_list>	//提供初始化列表的定义
using namespace std;


void p(initializer_list<string> ls)
{
	for (const auto &i : ls)
	{
		cout << i << " ";
	}
}
int main()
{
	p({ "AAA","ADAD","dadad" });

	return 0;
}