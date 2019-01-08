#include <iostream>
#include "inheritance.h"

using std::cin;
using std::cout;
using std::endl;
void f()
{
	const char *a = "abc";
	cout << (int)a << endl;
}
int main()
{
	double g[] = { 77.2,66,3,99 };
	Student s1("Mike",g,3);
	s1.show();
	cout << endl;
	cout << s1 << endl;
	const int a = 1;
	int *p = const_cast<int*>(&a);
	*p = 2;

	cout << "value a = " << a << endl;
	cout << "value * p =  "<< *p << endl;
	cout << "address a =  "<< &a << endl;
	cout << "address p =  "<< p << endl;
	const char* b = "abc";
	f();
	cout << (int)b << endl;

}