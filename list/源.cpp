#include <iostream>
#include <vector>
#include <list>
#include <algorithm>//ʹ��for_each,copy
#include <iterator>
#include <stack>
using namespace std;

void show(const int &n)
{
	cout << n << " ";
}
int main()
{
	stack<int> a;
	list<int> one(5, 2);
	vector<int> one1 = { 1,2,3,4,5 };
	int stuff[5] = { 1,2,4,8,6 };
	list<int> two;

	for_each(one.begin(), one.end(),show);
	cout << endl;
	for_each(one1.begin(), one1.end(),show);//for_each������������������random_shuffle()��sortҪ������֧���������,��Ϊ��Ҫ����
	cout << endl;
	random_shuffle(one1.begin(), one1.end());
	//random_shuffle(one.begin(), one.end());//list����֧���������
	for_each(one1.begin(), one1.end(), show);
	cout << endl;
	cout << endl;
	two.insert(two.begin(), stuff, stuff + 5);
	int more[6] = { 6,4,2,4,6,5 };
	list<int> three(two);
	//three.insert(three.end(), more, more + 6);//��copyʹ�õ��������һ��
	copy(more, more + 6, insert_iterator<list<int> >(three,three.end()));
	cout << "List one:";
	for_each(one.begin(), one.end(), show);
	cout << endl;
	cout << "List two:";
	for_each(two.begin(), two.end(), show);
	cout << endl;
	cout << "List three:";
	for_each(three.begin(), three.end(), show);
	three.remove(2);//ɾ��list�����е�2��������ɾ����2��Ԫ��
	cout << endl;
	cout << "List three minus 2s:";
	for_each(three.begin(), three.end(), show);
	cout << endl;
	three.splice(three.begin(), one);
	cout << "List three after splice:";
	for (auto x : three)show(x);
	cout << endl;
	cout << "List one after splice:";
	for (auto x : one)show(x);
	cout << endl;
	three.unique();
	cout << "List three after unique:";
	for (auto x : three)show(x);
	cout << endl;
	three.sort();
	three.unique();
	cout << "List three after sort & unique:";
	for (auto x : three)show(x);
	cout << endl;
	two.sort();
	three.merge(two);
	cout << "Sorted two merged into three:";
	for (auto x : three)show(x);
	cout << endl;
	cout << "List two after merge:";
	for (auto x : two)
		show(x);
	cout << endl;
}

