#include <iostream>
#include <string>
#include <initializer_list>	//�ṩ��ʼ���б�Ķ���
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