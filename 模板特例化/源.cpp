#include <iostream>
#include <string>
using std::string;
using std::cout;
using std::endl;

template <typename Type1, typename Type2>
class CNoOperatorAdd
{
public:
	Type1 member_int;
	Type2 member_string;
	CNoOperatorAdd() : member_int(1), member_string("a") {};
};
/*--------------------------------------------------------------*/
//类模板部分特例化:即部分特例化模板参数列表是原始模板的参数列表的一个子集或者是一个特例化版本
template <typename Type1>//子集
class CNoOperatorAdd<Type1, double>
{
public:
	Type1 member_int;
	string member_string;
	CNoOperatorAdd() : member_int(10), member_string("b") {};
};
template <typename Type1, typename Type2>
class CNoOperatorAdd<Type1&&, Type2&&>//特例化为右值引用
{
public:
	int member_int;
	string member_string;
	CNoOperatorAdd() : member_int(20), member_string("a") {};
};
/*---------------------------------------------------------------*/
//模板函数没有部分特例化，实质上用函数重载实现
template <typename Type1, typename Type2>
int Add(Type1 a, Type2 b)
{
	return a + b;
}
//考虑是否与上面产生二义性（yes），如果注释下面!!!的模板，则调用Add(2,4)无法区分
//由此看出函数模板没有部分特例化(参数特例化是部分特例化一种)，会产生重载冲突
//template <typename Type4, typename Type5>
//int Add(Type4 &&a, Type5 &&b)
//{
//	return 80;
//}

template <>
int Add(typename CNoOperatorAdd<int, string> a, typename CNoOperatorAdd<int, string> b)
{
	return a.member_int + b.member_int;
}
//！！！！
template <typename Type1>
int Add(Type1 a, int b)
{
	return 40;
}
template <typename Type4, typename Type5>
int Add(Type4 *a, Type5 *b)
{
	return 60;
}

template <typename T1,typename T2>
int Add(CNoOperatorAdd<T1,T2> a, CNoOperatorAdd<T1,T2> b)
{
	return a.member_int + b.member_int;
}


int main()
{
	int i = 2;
	int j = 4;
	CNoOperatorAdd<int, string> ci;//member_int为1
	CNoOperatorAdd<int, string> cj;
	cout << Add(2, 4) << endl;
	cout << Add(&i, &j) << endl;
	cout << Add(ci, cj) << endl;
	return 0;
}
