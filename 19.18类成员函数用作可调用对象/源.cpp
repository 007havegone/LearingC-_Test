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
	
	auto fp = &string::empty;//���Ա����ָ��
	/*�޷�ֱ��������ִ�ж���
	auto i = find_if(str.begin(), str.end(), fp);*/


	//ʹ��function����һ���ɵ��ö���,��ʾָ��this�β�
	cout << "functionģ��ʹ��" << endl;
	function<bool(const string&)> fcn = &string::empty;
	auto i = find_if(str.begin(), str.end(), fcn);
	cout << "�մ����±�Ϊ: " << i-str.begin() << endl;
	//ʹ��mem_fn����һ���ɵ��ö��󣬱������Զ��ҳ��β�����
	auto m1 = mem_fn(&A::print);
	auto m2 = mem_fn(&A::draw);
	cout << "mem_fnģ��ʹ��" << endl;
	(find_if(str.begin(), str.end(), mem_fn(&string::empty))
				== str.end()) ? cout << "1" : cout << "2"; cout << '\n';
	(find_if(pstr.begin(), pstr.end(), mem_fn(&string::empty))
				== pstr.end()) ? cout << "1" : cout << "2"; cout << '\n';
	//------------------------------------------------------
	vector<A> va = { A(),A(),A() };
	vector<shared_ptr<A>> vpa = { make_shared<A>(),
			make_shared<A>() ,make_shared<A>() };
	//ʹ��bind����һ���ɵ��ö���Ҳ��Ҫ��ʾ����this�βΣ���ָ�������
	auto f = bind(&A::draw, _1);//��ָ�������
	
	cout << "ʹ��bind f" << endl;
	for_each(va.begin(), va.end(), f);
	cout << endl;
	for_each(vpa.begin(), vpa.end(), f);
	cout << endl;
	//------------------------------------------------------

	cout << "function��bind���ʹ��\n";
	void (A::*fpA)(int) const;//fpaΪһ��ָ��void ()�ĺ���ָ��
	fpA = &A::print;
	function<void(const A&)> fun1 = &A::draw;
	function<void(const A&,int)> fun2 = &A::print;
	function<void (shared_ptr<A>)>fun3 = &A::draw;
	function<void (shared_ptr<A>,int)> fun4 = &A::print;
	for_each(va.begin(), va.end(),fun1);
	cout << '\n';
	auto bp = bind(fun2, _1, 16);//���function,ֻ��������
	auto bp2 = bind(fun4, _1, 20);//���function��ֻ����ֻ��ָ��
	for_each(va.begin(), va.end(),bp);
	cout << '\n';
	for_each(vpa.begin(), vpa.end(), fun3);
	for_each(vpa.begin(), vpa.end(), bp2);
}