#include <iostream>
using namespace std;
//��using����
using Fun = void(*)();
//��typedef����
typedef void (*fun)();

void a() {
	cout << "a()" << endl;
}
void b() {
	cout << "b()" << endl;
}
//���÷�������
auto getFun()->decltype(fun()) {
	return a;
}
decltype(Fun()) getAf() {
	return b;
}
//ԭʼ���壬����һ��void (*)()
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
