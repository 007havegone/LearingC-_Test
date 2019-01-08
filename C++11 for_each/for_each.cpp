#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

struct Node
{
	int x;
	int y;
	Node(int m, int n) :x(m), y(n) {}
};
bool operator<(Node& n1, Node& n2)
{
	return n1.x > n2.x;
}
bool comp(Node& n1, Node& n2)
{
	return n1.x < n2.x;
}
void show(Node& n)
{
	n.x++;
	n.y++;
	cout << n.x << "," << n.y << endl;
}
int main()
{
	vector<Node> v;
	for (int i = 1; i <= 10; i++)
		v.push_back(Node(i * 2, i * 5));
	sort(v.begin(), v.end());
	for_each(v.begin(), v.end(), show);
	for (auto a : v)
		show(a);
	sort(v.begin(), v.end(), comp);
	for (auto a = v.begin(); a != v.end(); a++)
		show(*a);


}