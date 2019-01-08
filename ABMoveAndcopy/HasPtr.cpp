#include "HasPtr.h"
#include <iostream>
using std::cout;
using std::endl;
using std::string;
void swap(HasPtr &p1, HasPtr &p2)
{
	using std::swap;
	cout << "use a swap" << endl;
	swap(p1.i, p2.i);
	swap(p1.pstr, p2.pstr);
}

HasPtr::HasPtr(const HasPtr& p) :pstr(new string(*p.pstr)), i(p.i)
{
	cout << "use a copy construct" << endl;
}

HasPtr & HasPtr::operator=(const HasPtr & p)
{
	cout << "use a operator " << endl;
	pstr = new string(*p.pstr);
	i = p.i;
	return *this;
}

