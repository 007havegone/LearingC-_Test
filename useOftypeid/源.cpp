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
//Ҫ���麯���Ż��typeid���ʽ��ֵ������Ϊ��̬���ͼ�ָ����������
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