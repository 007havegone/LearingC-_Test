#include <iostream>
#include <string>
using namespace std;
class Foo {
public:
	Foo(int i = 11) :a(i) {
	}
	Foo& operator=(const Foo&f)
	{
		a = f.a;
		return *this;
	}
	friend ostream& operator<<(ostream& os, Foo& f)
	{
		os << f.a << endl;
	}
	//void print() const &//�κ�����,�������������ܵ���
	//{
	//	cout << "const &"<<a << endl;
	//}
	Foo sorted()const & {
		Foo ret(*this);
		return ret.sorted();
	}
	void print() &&
	{
		cout << "&&" <<a << endl;
	}
	void print() &
	{
		cout << "& " <<a << endl;
	}
private:
	int a = 11;
};
Foo& getFooRef()
{
	return *(new Foo());
}
Foo getFoo()
{
	return Foo();
}
int main()
{
	getFooRef().print();
	getFoo().print();
	(getFooRef() = 15).print();
	Foo a(100);
	a = 200;
	a.print();
	a.sorted();
}