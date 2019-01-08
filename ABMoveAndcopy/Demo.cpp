#include "HasPtr.h"
#include <iostream>
#include <string>
using namespace std;
HasPtr getHas()
{
	HasPtr t;
	cout << "return a temp " << endl;
	return t;
}
int main()
{
	HasPtr p1;
	HasPtr p2;

	cout << endl;
	p1 = p2;
	cout << endl;
	p1 = getHas();
}