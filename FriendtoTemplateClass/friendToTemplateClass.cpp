/*1����ģ����Ԫ����
  2��Լ��ģ����Ԫ
  3��*/
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
	friend void report1(Demo& d);//ʹ��ģ����Ϊ����,��Ҫ���廯��������

	friend void count2<T>();//���������൱�ڽ��ⲿ��ģ�庯�����廯
	friend void report2<>(Demo<T>& d);//�ȼ���friend void report2<Demo>(Demo& d)

	template <typename C, typename D> friend void count3(C&, D&);//��Լ��ģ����Ԫ
};

template <typename T>
int Demo<T>::b = 0;
/*��Ԫ����,���ǳ�Ա����,��û���ṩ�������,ֻ�ܷ���ȫ�ֱ���;
����ʹ��ȫ��ָ����ʷ�ȫ�ֶ���;
���Դ����Լ��Ķ���;���Է��ʶ����ڶ����ģ����ľ�̬��Ա*/
void count1()	//1����ģ����Ԫ����
{
	cout << "Demo<int>::b = " << Demo<int>::b << endl;
	cout << "Demo<double>::b = " << Demo<double>::b << endl;
}
void report1(Demo<int>& d)//�������Ͷ�����ָ�����廯��int�汾
{
	cout << "Demo<int>::a = " << d.a << endl;
}
void report1(Demo<double>& d)//double�汾

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