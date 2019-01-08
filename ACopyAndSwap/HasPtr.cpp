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
HasPtr::HasPtr(HasPtr &&p)noexcept :pstr(p.pstr), i(p.i)
{
	p.pstr = nullptr;
	cout << "use a move construct" << endl;
}
HasPtr& HasPtr::operator=(HasPtr p)
{
	cout << "use copy swap operator" << endl;
	swap(*this, p);
	return *this;
}
