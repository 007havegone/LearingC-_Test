#pragma once
#include <iostream>
#include <functional>
using namespace std;
//template<typename T,typename F>
//T use_f(T v, F f)
//{
//	static int count = 0;
//	count++;
//	std::cout << " use_f count = " << count
//		<< ", &count = " << &count << std::endl;
//	return f(v);
//}
//定义function模板,直接将函数第二个参数定义为function
template<typename T>
T use_f(T v, std::function<T (T)> f)
{
	static int count;
	count++;
	cout << " use_ count = " << count
		<< ",&count = " << &count << endl;
	return f(v);
}

class Fp
{
private:
	double z_;
public:
	Fp(double z = 1.0) :z_(z) {}
	double operator()(double p) { return z_ * p; }
};
class Fq
{
private:
	double z_;
public:
	Fq(double z = 1.0) :z_(z) {}
	double operator()(double q) { return q * z_; }
};