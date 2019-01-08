#include <iostream>
#include <unordered_set>
using namespace std;

struct Sales_data
{
	string name;
	int isbn;
};

size_t hasher(const Sales_data &sd)
{
	auto i = hash<string>();
	return i(sd.name);
}
bool eqOp(const Sales_data &lhs, const Sales_data &rhs)
{
	return lhs.name == rhs.name;
}
int main()
{
	unordered_multiset<Sales_data, decltype(hasher)*, decltype(eqOp)*> bookstore(42, hasher, eqOp);

}