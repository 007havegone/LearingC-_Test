#include <iostream>
using namespace std;
//用using别名
using Fun = void(*)();
//用typedef别名
typedef void (*fun)();

void a() {
	cout << "a()" << endl;
}
void b() {
	cout << "b()" << endl;
}
//后置返回类型
auto getFun()->decltype(fun()) {
	return a;
}
decltype(Fun()) getAf() {
	return b;
}
//原始定义，返回一个void (*)()
void(*getAvoidFun())() {
	return a;
}
int main()
{
	fun pa = a;
	pa();
	pa = b;
	fun paa = getFun();
	paa();
	Fun pb = getAf();
	pb();
	Fun pc = getAvoidFun();
	pc();
}
