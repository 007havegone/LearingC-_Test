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
//typeid参数为指针时，为静态类型
//引用则为所引用的类型，忽略顶层const
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