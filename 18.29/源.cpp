#include <iostream>
using namespace std;

class Class {
public:
	Class() {
		cout << "Class" << endl;
	}
};
class Base : public Class {
public:
	Base() {
		cout << "Base" << endl;
	}
};
class D1 : virtual public Base {
public:
	D1() {
		cout << "D1 " << endl;
	}
};
class D2 : virtual public Base {
public:
	D2() {
		cout << "D2" << endl;
	}
};
class MI :public D1, public D2 {
public:
	MI() :Base(), D1(), D2()
	{
		cout << "MI" << endl;
	}
};
class Final :public MI, public Class {
public:
	Final() :MI(), Class() {
		cout << "Final" << endl;
	}
};
int main()
{
	Final f;//可以验证Final有1份Base，2分Class

}