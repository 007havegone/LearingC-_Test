#include <iostream>
using namespace std;

class P {
public:
	virtual void show()
	{
		cout << "P Vshow()" << endl;
	}
	void prin()
	{
		cout << "P prin()" << endl;
	}
};
class C :public P
{
public:
	virtual void show(int x) //override����Ӹñ�ʶ�����ǹؼ��֣���������Ƿ�͸���һ��
	{
		cout << "C Vshow(int x)" << endl;
	}
	void prin(int n)
	{
		cout << "C prin()" << endl;
	}
};
int main()
{
	C c;
	P p;
	P *pc = new C();
	cout << "C:";
	c.show(11);
	c.prin(12);

	cout << "P:";
	p.show();
	p.prin();
	
	cout << "Pc:";
	pc->show();
	pc->prin();

}