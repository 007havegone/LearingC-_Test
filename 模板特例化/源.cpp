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
//��ģ�岿��������:������������ģ������б���ԭʼģ��Ĳ����б��һ���Ӽ�������һ���������汾
template <typename Type1>//�Ӽ�
class CNoOperatorAdd<Type1, double>
{
public:
	Type1 member_int;
	string member_string;
	CNoOperatorAdd() : member_int(10), member_string("b") {};
};
template <typename Type1, typename Type2>
class CNoOperatorAdd<Type1&&, Type2&&>//������Ϊ��ֵ����
{
public:
	int member_int;
	string member_string;
	CNoOperatorAdd() : member_int(20), member_string("a") {};
};
/*---------------------------------------------------------------*/
//ģ�庯��û�в�����������ʵ�����ú�������ʵ��
template <typename Type1, typename Type2>
int Add(Type1 a, Type2 b)
{
	return a + b;
}
//�����Ƿ���������������ԣ�yes�������ע������!!!��ģ�壬�����Add(2,4)�޷�����
//�ɴ˿�������ģ��û�в���������(�����������ǲ���������һ��)����������س�ͻ
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
//��������
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
	CNoOperatorAdd<int, string> ci;//member_intΪ1
	CNoOperatorAdd<int, string> cj;
	cout << Add(2, 4) << endl;
	cout << Add(&i, &j) << endl;
	cout << Add(ci, cj) << endl;
	return 0;
}
