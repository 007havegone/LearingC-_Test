#include <iostream>
#include <string>
using std::cout;
using std::endl;
using std::string;

template <typename T>
class beta
{
private:
	template <typename V>//nest class,only using in the beat class
	class hold;//可以将模板类定义在外部
	
	hold<T> q;//template class member
	hold<int> n;
public:
	beta(T t, int i) :q(t), n(i) {}
	template<typename U>
	auto blab(U u, T t)->decltype((n.value() + q.value())*u / t)
	{
		return (n.value() + q.value())*u / t;//适用类型自动转换
	}
	void show()const { q.show(); n.show(); }
};
//template <typename T>
//	template<typename U>
//	在外部定义不行,用auto的时候无法使用this指针，即静态函数
//	auto beta<T>::blab(U u, T t)->decltype((n.value() + q.value())*u / t)
//	{
//		return (n.value() + q.value())*u / t; 
//	}
template <typename T>
	template<typename V>
	class  beta<T>::hold
	{
	private:
		V val;
	public:
		hold(V v = 0) :val(v) {}
		void show()const { cout << val << endl; }
		V value()const { return val; }
	};
int main()
{
	beta<double> guy(3.5, 5);//T为double，q的V设置为double
	guy.show();
	cout << guy.blab(10, 2.3) << endl;//U为int

}