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
	class hold;//���Խ�ģ���ඨ�����ⲿ
	
	hold<T> q;//template class member
	hold<int> n;
public:
	beta(T t, int i) :q(t), n(i) {}
	template<typename U>
	auto blab(U u, T t)->decltype((n.value() + q.value())*u / t)
	{
		return (n.value() + q.value())*u / t;//���������Զ�ת��
	}
	void show()const { q.show(); n.show(); }
};
//template <typename T>
//	template<typename U>
//	���ⲿ���岻��,��auto��ʱ���޷�ʹ��thisָ�룬����̬����
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
	beta<double> guy(3.5, 5);//TΪdouble��q��V����Ϊdouble
	guy.show();
	cout << guy.blab(10, 2.3) << endl;//UΪint

}