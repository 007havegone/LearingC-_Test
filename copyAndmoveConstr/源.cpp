#include <iostream>
#include <string>
using namespace std;

class Node {
public:
	Node() :a(100), str("Hello") {};
	Node(Node && n)noexcept :a(n.a), str(n.str) { cout << "use a move construct" << endl; }
	Node(const Node& n) :a(n.a), str(n.str) { cout << "use a copy construct" << endl; }
	Node& operator=(Node n)
	{
		cout << "use ope" << endl;
		swap(*this, n);
		return *this;
	}
	friend void swap(Node& n1, Node &n2)
	{
		using std::swap;
		swap(n1.a, n2.a);
		swap(n1.str, n2.str);
	}
	~Node(){}
private:
	int a;
	string str;
};
Node getNode()
{
	Node t;
	return t;
}
int main()
{
	Node a;
	Node b;
	a = b;
	a = getNode();
	
}