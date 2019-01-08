#include "worker0.h"
#include <iostream>
const int LIM = 4;
int main()
{
	Waiter bob("Bob Apple", 314L, 5);
	Singer bev("Beverly Hills", 522L, 3);
	Waiter w_temp;
	Singer s_temp;

	Worker *pw[LIM] = { &bob,&bev,&w_temp,&s_temp };
	int i;
	for (i = 2; i < LIM; i++)
		pw[i]->Set();
	for (i = 0; i < LIM; i++) 
	{
		pw[i]->Show();
		std::cout << std::endl;
	}
	SingerWaiter sw;
	//Worker *w = &sw;	������ֱ�Ӹ���
	Worker *pw1 =(Waiter*)&sw;//Worker in Waiterǿ��ת��
	//Worker *pw2 = (Singer*)&sw;//Worker in Singer
	//Waiter *pw3 = &sw; ���ᱨ��
	sw.Singer::Show();
	return 0;
}