#include <iostream>
#include <string>
using namespace std;

class exceptionType {
public:
	string what()
	{
		return "exceptionType";
	}
};
namespace mathLib {
	namespace MatrixLiib {
		class matrix {
			friend matrix operator*(const matrix&, const matrix&);
		public:
			matrix(int t=1) :a(t){}
			int a;
		};
		/*matrix operator*(const matrix &a1, const matrix &a2)
		{
			return matrix(a1.a*a2.a);
		}*/
	}
}
mathLib::MatrixLiib::matrix mathLib::MatrixLiib::operator*(const matrix&a1, const matrix&a2)
{
	return matrix(a1.a*a2.a);
}
void fun()
{
	throw new exceptionType();
}
void funthrow()
{
	try {
		fun();
	}
	catch (exceptionType *pe) {
		cout << pe->what() << endl;
		throw;
	}
}
void funnothr() noexcept(0)
{
	//throw 1;
}
namespace hello {
	int i = 2;
	class A {
		friend void f2() {}
		friend void f1(const A&a) {
			cout << i << endl;
		}
	};
}
struct Node
{
	int men1;
	string men2;
};
template<typename T>
void swap(T &v1, T &v2)
{
	using std::swap;
	swap(v1.men1, v2.men1);
}
int i = 1;
int main()
{
	int i = 4;
	cout << noexcept(fun) << endl;
	try {
		funthrow();
	}
	catch (...)
	{
		cout << "catch thorw;" << endl;
	}
	funnothr();
	mathLib::MatrixLiib::matrix a1(15);
	mathLib::MatrixLiib::matrix a2(16);
	mathLib::MatrixLiib::matrix a3 = a1 * a2;
	cout << i << endl;
	cout << hello::i << endl;
	cout << ::i << endl;
	hello::A a;
	f1(a);
	//f2();
	Node n1{ 10,"n1" };
	Node n2{ 20,"n2" };
	::swap(n1, n2);
	cout << n1.men1 << " " << n1.men2 << endl;
	cout << n2.men1 << " " << n2.men2 << endl;
}