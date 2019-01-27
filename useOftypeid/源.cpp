#include <iostream>
using namespace std;

class Base {
public:
	virtual ~Base() = default;
};
class Derived :public Base {
public:
	virtual ~Derived() = default;
};
//要有虚函数才会对typeid表达式求值，否则为静态类型即指针引用类型
int main()
{
	Derived *dp = new Derived;
	const Base &bp = *dp;
	if (typeid(bp) == typeid(Derived))
	{
		cout << "Derived" << endl;
	}
	else if (typeid(bp) == typeid(Derived*))
	{
		cout << "Derived *" << endl;
	}
	else if (typeid(bp) == typeid(Derived&))
	{
		cout << "Derived &" << endl;
	}
	cout << typeid(42).name() << ",";
	cout << typeid("str").name() << ",";
	cout << typeid(dp).name() << ",";
	cout << typeid(*dp).name() << endl;
	cout << typeid(std::string).name() << endl;

}