#ifndef TEMPLATE_T_
#define TEMPLATE_T_
#include <iostream>
using std::ostream;
using std::cout;
using std::endl;

//definition 1: T&
template<typename T>
ostream& print(ostream& os,const T& t)
{
	return cout << "value: " << t << endl;
}
//definition 2:const T*
template<typename T>
ostream& print(ostream& os,T* p)
{
	os << "pointer: " << p << " ";
	return print(os,*p);
}
template<typename T>
class Node {
public:
	Node(const T&t):a(t){}
	friend ostream& operator<<(ostream& os, const Node&n)
	{
		return os << n.a;
	}
private:
	T a;
};
template<typename T>
void Fun(const T&t)
{
	cout << "Fun " << t << endl;
}

class NodeA {
public:
	template<typename T>void p(const T&t);
};
template<typename T>
inline void NodeA::p(const T & t)
{
	cout << "Hello" << endl;
}


#endif // !TEMPLATE_T_

