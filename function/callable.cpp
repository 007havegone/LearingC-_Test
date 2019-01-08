#include "somedef.h"
#include <iostream>
#include <functional>
using namespace std;

double dub(double x) { return 2.0*x; }
double square(double x) { return x * x; }

int main()
{	//count地址一共有5个，说明模板实例化了5次
	double y = 1.21;
	//第一第二为函数指针，使用 double(*)(double)类型相同，使用同一个count
	//cout << "Function pointer dub:\n";
	//cout << " " << use_f(y, dub) << endl;
	//cout << "Function pointer square:\n";
	//cout << " " << use_f(y, square) << endl;
	////第三第四使用函数对象，对象不同，属于不同的count
	//cout << "Function object Fp:\n";
	//cout << " " << use_f(y, Fp(5.0)) << endl;
	//cout << "Function object Fq:\n";
	//cout << " " << use_f(y, Fq(5.0)) << endl;
	////第五第六使用lambda表达式，属于不同的count
	//cout << "Lambda expression 1:\n";
	//cout << " " << use_f(y, [](double x) {return x * x; });
	//cout << "Lambda expression 2:\n";
	//cout << " " << use_f(y, [](double x) {return x + x / 2.0; });
	
	//使用包装器function后是他们属于同一类型F，模板只实例化一次
	/*function<double(double)> f1 = dub;
	function<double(double)> f2 = square;
	function<double(double)> f3 = Fq(10.0);
	function<double(double)> f4 = Fp(10.0);
	function<double(double)> f5 = [](double x) {return x * x; };
	function<double(double)> f6 = [](double u) {return u + u / 2.0; };*/
	//typedef function<double(double)> fdd;//可以定义一个临时对象, fdd(dub)调用
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