#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include <algorithm>
#include <functional>
#include <random>
using namespace std::placeholders;
using namespace std;

class A {
public:
	A() {
		a = ud(r);
	}
	void print(int x) const {
		cout << x << " " << a << " ";
	}
	void draw()const {
		cout << a << " ";
	}
private:
	int a;
	static default_random_engine r;
	static uniform_int_distribution<int> ud;
};
default_random_engine A::r;
uniform_int_distribution<int> A::ud(0, 50);
int main()
{
	vector<string> str{ "Hello","wORLD","" };
	vector<string*> pstr{ new string("new"),
			new string("hel"),new string("wo") };
	
	auto fp = &string::empty;//类成员函数指针
	/*无法直接用做可执行对象
	auto i = find_if(str.begin(), str.end(), fp);*/


	//使用function生成一个可调用对象,显示指出this形参
	cout << "function模板使用" << endl;
	function<bool(const string&)> fcn = &string::empty;
	auto i = find_if(str.begin(), str.end(), fcn);
	cout << "空串的下标为: " << i-str.begin() << endl;
	//使用mem_fn生成一个可调用对象，编译器自动找出形参类型
	auto m1 = mem_fn(&A::print);
	auto m2 = mem_fn(&A::draw);
	cout << "mem_fn模板使用" << endl;
	(find_if(str.begin(), str.end(), mem_fn(&string::empty))
				== str.end()) ? cout << "1" : cout << "2"; cout << '\n';
	(find_if(pstr.begin(), pstr.end(), mem_fn(&string::empty))
				== pstr.end()) ? cout << "1" : cout << "2"; cout << '\n';
	//------------------------------------------------------
	vector<A> va = { A(),A(),A() };
	vector<shared_ptr<A>> vpa = { make_shared<A>(),
			make_shared<A>() ,make_shared<A>() };
	//使用bind生成一个可调用对象，也需要显示给出this形参，可指针可引用
	auto f = bind(&A::draw, _1);//可指针可引用
	
	cout << "使用bind f" << endl;
	for_each(va.begin(), va.end(), f);
	cout << endl;
	for_each(vpa.begin(), vpa.end(), f);
	cout << endl;
	//------------------------------------------------------

	cout << "function和bind结合使用\n";
	void (A::*fpA)(int) const;//fpa为一个指向void ()的函数指针
	fpA = &A::print;
	function<void(const A&)> fun1 = &A::draw;
	function<void(const A&,int)> fun2 = &A::print;
	function<void (shared_ptr<A>)>fun3 = &A::draw;
	function<void (shared_ptr<A>,int)> fun4 = &A::print;
	for_each(va.begin(), va.end(),fun1);
	cout << '\n';
	auto bp = bind(fun2, _1, 16);//结合function,只可以引用
	auto bp2 = bind(fun4, _1, 20);//结合function。只可以只能指针
	for_each(va.begin(), va.end(),bp);
	cout << '\n';
	for_each(vpa.begin(), vpa.end(), fun3);
	for_each(vpa.begin(), vpa.end(), bp2);
}