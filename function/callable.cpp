#include "somedef.h"
#include <iostream>
#include <functional>
using namespace std;

double dub(double x) { return 2.0*x; }
double square(double x) { return x * x; }

int main()
{	//count��ַһ����5����˵��ģ��ʵ������5��
	double y = 1.21;
	//��һ�ڶ�Ϊ����ָ�룬ʹ�� double(*)(double)������ͬ��ʹ��ͬһ��count
	//cout << "Function pointer dub:\n";
	//cout << " " << use_f(y, dub) << endl;
	//cout << "Function pointer square:\n";
	//cout << " " << use_f(y, square) << endl;
	////��������ʹ�ú������󣬶���ͬ�����ڲ�ͬ��count
	//cout << "Function object Fp:\n";
	//cout << " " << use_f(y, Fp(5.0)) << endl;
	//cout << "Function object Fq:\n";
	//cout << " " << use_f(y, Fq(5.0)) << endl;
	////�������ʹ��lambda���ʽ�����ڲ�ͬ��count
	//cout << "Lambda expression 1:\n";
	//cout << " " << use_f(y, [](double x) {return x * x; });
	//cout << "Lambda expression 2:\n";
	//cout << " " << use_f(y, [](double x) {return x + x / 2.0; });
	
	//ʹ�ð�װ��function������������ͬһ����F��ģ��ֻʵ����һ��
	/*function<double(double)> f1 = dub;
	function<double(double)> f2 = square;
	function<double(double)> f3 = Fq(10.0);
	function<double(double)> f4 = Fp(10.0);
	function<double(double)> f5 = [](double x) {return x * x; };
	function<double(double)> f6 = [](double u) {return u + u / 2.0; };*/
	//typedef function<double(double)> fdd;//���Զ���һ����ʱ����, fdd(dub)����
	cout << "Function pointer dub:\n";
	cout << " " << use_f<double>(y, dub) << endl;
	cout << "Function pointer square:\n";
	cout << " " << use_f<double>(y, square) << endl;
	cout << "Function Object Fq:\n";
	cout << " " << use_f<double>(y, Fq(10.0)) << endl;
	cout << "Function Object Fp:\n";
	cout << " " << use_f<double>(y, Fp(10.0)) << endl;
	cout << "Lambda expression1:\n";
	cout << " " << use_f<double>(y, [](double x) {return x * x; }) << endl;
	cout << "Lambda expression2:\n";
	cout << " " << use_f<double>(y, [](double x) {return x + x / 2.0; }) << endl;


	return 0;
}