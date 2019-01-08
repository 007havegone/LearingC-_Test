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
	virtual void show(int x) //override，添加该标识符，非关键字，会检测参数是否和父类一致
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