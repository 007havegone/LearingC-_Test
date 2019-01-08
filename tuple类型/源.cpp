#include <iostream>
#include <vector>
#include <functional>
#include <list>
#include <algorithm>
#include <tuple>
#include <string>
#include <map>
using namespace std;
using std::placeholders::_1;
class  Node
{
	int a;
	double b;
};
struct Print
{
	void operator()(const int&t)
	{
		cout << "t[" << a++ << "] = " << t << endl;
	}
private:
	int a = 0;
};

void anprint(const int&t, int &cnt)
{
	cout << "vec[" << cnt++ << "] = " << t << endl;
}
int main()
{
	int cnt = 0;
	map<const char*, function<void(const int&)>> myFun_mp;
	myFun_mp.insert(make_pair("1", Print()));
	myFun_mp.insert(pair<const char*, function<void(const int&)>>
					("2", [](const int&t) { cout << t << " "; }));
	myFun_mp.insert(make_pair("3", bind(anprint, _1, ref(cnt))));

	tuple<int, vector<int>, list<double>, string> someValu
					{ 10,{1,2,3,4,5},{5,4,3,2,1},"Hello world" };
	tuple<int, double, string> defau;
	tuple<int, double, string> t(15,16,"Great");
	cout << get<0>(someValu) << endl;
	cout << get<1>(someValu).at(0) << endl;
	cout << (*get<2>(someValu).begin()) << endl;
	if (defau<t)
		cout << "someValu < defau" << endl;

	typedef decltype(someValu) someType;
	cout << "tuple_size = " <<tuple_size <someType>::value << endl;
	tuple_element<1, someType>::type vec{ 100,200,300 };
	for_each(vec.begin(), vec.end(), myFun_mp.at("1"));
	cout << endl;
	for_each(vec.begin(), vec.end(), myFun_mp["2"]);
	cout << endl;
	for_each(vec.begin(), vec.end(),myFun_mp["3"] );
}