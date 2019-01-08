/*1、非模板友元函数
  2、约束模板友元
  3、*/
#include <iostream>
using std::cout;
using std::endl;

template <typename TT>void count2();
template <typename TT>void report2(TT& t);
template <typename T>
class Demo{
private:
	T a;
	static int b;
public:
	Demo(T t) :a(t) { b++; };
	friend void count1();
	friend void report1(Demo& d);//使用模板类为参数,需要具体化参数类型

	friend void count2<T>();//类中声明相当于将外部的模板函数具体化
	friend void report2<>(Demo<T>& d);//等价于friend void report2<Demo>(Demo& d)

	template <typename C, typename D> friend void count3(C&, D&);//非约束模板友元
};

template <typename T>
int Demo<T>::b = 0;
/*友元函数,不是成员函数,又没有提供对象参数,只能访问全局变量;
可以使用全局指针访问非全局对象;
可以创建自己的对象;可以访问独立于对象的模板类的静态成员*/
void count1()	//1、非模板友元函数
{
	cout << "Demo<int>::b = " << Demo<int>::b << endl;
	cout << "Demo<double>::b = " << Demo<double>::b << endl;
}
void report1(Demo<int>& d)//对于类型都必须指出具体化，int版本
{
	cout << "Demo<int>::a = " << d.a << endl;
}
void report1(Demo<double>& d)//double版本

{
	cout << "Demo<double>::a = " << d.a << endl;
}


template <typename TT>
void report2(Demo<TT>& d)
{
	cout << d.a << endl;
}
template <typename TT>
void count2()
{
	cout << "Demo<TT>::b = "<< Demo<TT>::b << endl;
}



template<typename C, typename D>
void count3(C &c, D &d)
{
	cout << "c.a = " <<c.a << ", d.a = " << d.a << endl;
}

int main()
{
	Demo<int> a(10);
	Demo<double> b(11.11);
	Demo<double> b1(10.2);
	count1();
	count2<int>();
	count2<double>();
	count3(a, b);
	return 0;
}