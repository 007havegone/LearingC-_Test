#include <iostream>
using namespace std;
class A {
public:
	A() = default;
	virtual ~A() = default;
};
class B:public A {
public:
	B() = default;
	virtual~B() = default;
};
class C :public B {
public:
	C() = default;
	virtual~C() = default;
};
//typeid����Ϊָ��ʱ��Ϊ��̬����
//������Ϊ�����õ����ͣ����Զ���const
int main()
{
	A*pa = new C;
	cout << typeid(pa).name() << endl;
	C cobj;
	A& ra = cobj;
	cout << typeid(&ra).name() << endl;
	B*px = new B;
	A& raa = *px;
	cout << typeid(raa).name() << endl;
}