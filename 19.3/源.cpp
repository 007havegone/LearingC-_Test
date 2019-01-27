#include <iostream>
using namespace std;

class A {
public:
	A() = default;
	virtual ~A() = default;
	virtual void print() {
		cout << "A" << endl;
	}
};
class B :public A {
public:
	B() = default;
	~B() = default;
	void print() override {
		cout << "B" << endl;
	}
};
class C :public B {
public:
	C() = default;
	~C() = default;
	void print() override {
		cout << "C" << endl;
	}
};
class D :public B, public A {
public:
	D() = default;
	~D() = default;
	void print() override {
		A::print();
		B::print();
		cout << "D" << endl;
	}
};

int main()
{
	A *pa = new C;
	if (B *pb = dynamic_cast<B*>(pa))
		pb->print();
	else {
		cout << "1×ª»»Ê§°Ü" << endl;
	}
	B *pb = new B;
	if (C *pc = dynamic_cast<C*>(pb))
		pc->print();
	else
		cout << "2×ª»»Ê§°Ü" << endl;
	A *pa1 = new D;
	if (B* pb = dynamic_cast<B*>(pa1))
		pb->print();
	else
		cout << "3×ª»»Ê§°Ü" << endl;
	D* pd = new D;
	B* pa2 = dynamic_cast<B*>(pd);


	pa2->print();

}