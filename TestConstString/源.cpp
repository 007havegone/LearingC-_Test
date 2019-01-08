#include <iostream>
#include <vector>
using namespace std;

class Node
{
public:
	const static int a = 6;
	constexpr static double b = 6.5;
	static vector<int> vec;//不是字面量要在外部初始化
};

vector<int> Node::vec(Node::a);
//const int Node::a;
void fun(const int&e)
{
	cout << e << endl;
}
int main()
{
	cout << Node::a << endl;
	cout << Node::b << endl;
	cout << Node::vec.size() << endl;
	fun(Node::a);
}