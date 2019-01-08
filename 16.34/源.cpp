#include <iostream>
#include <type_traits>
#include <vector>
using namespace std;

template<typename It>
auto fcn(It b, It e)-> typename remove_reference<decltype(*b)>::type
{
	return *b;
}
template<typename It>
auto fcn2(It b, It e)-> decltype(*b + 0)
{
	return *b;
}
template<typename T> int compare(const T&, const T&);
int(*pf1)(const int&, const int&) = compare;

void func(int(*)(const int&, const int&));
void func(int(*)(const string&, const string&));

template<typename T>
void p(T&& t)
{

}
int main()
{
	vector<int> vec{ 5,4,6,2,1 };
	cout << fcn(vec.begin(), vec.end()) << endl;
	vector<string> vecs{ "Hello","world","school" };
	cout << fcn2(vec.begin(), vec.end()) << endl;
	func(compare<int>);
	const int a = 15;
	int b = 15;
	p(a);
	p(b);
	p(16);
}
