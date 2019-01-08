#include "LinkedList.h"
#include <iostream>
using std::cout;
using std::cin;
int main()
{
	LinkedList<int> linklist;
	for (int i = 1; i <= 20; i++)
		linklist.ListInsert(i * 3, i);
	linklist.ClearList();
	for (int i = 1; i <= 20; i++)
		linklist.ListInsert(i * 3, i);
	int t;
	linklist.getElement(5,t);
	linklist.ListInsert(100, 10);
	linklist.ListInsert(10, 1);
	int t2;
	linklist.ListDelete(t2, 1);
	cout << "��ǰ����Ϊ��" << linklist.getLength() << endl;
	linklist.TraverseList();
	cout << "t = " << t << endl;
	cout << "ɾ���ĵ�һ��Ԫ��t2 = " << t2 << endl;
	cout << "��ǰ�����Ƿ�Ϊ��:" << linklist.ListEmpty() << endl;
	linklist.ListDelete(t2, 3);
	linklist.ListDelete(t2, 5);
	linklist.ListDelete(t2, 12);
	linklist.ListDelete(t2, 19);//��ʱû��19��Ԫ��
	linklist.TraverseList();
	for (int i = 1; i <= 20; i++)
	{
		int ind = linklist.locateElem(i * 3);
		if (ind)
			cout << i * 3 << "�ǵ�" << ind << "��" << endl;
		else
			cout << "δ�ҵ�" << i * 3 << "��Ԫ��" << endl;
	}
}