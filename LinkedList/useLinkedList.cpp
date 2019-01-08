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
	cout << "当前长度为：" << linklist.getLength() << endl;
	linklist.TraverseList();
	cout << "t = " << t << endl;
	cout << "删除的第一个元素t2 = " << t2 << endl;
	cout << "当前链表是否为空:" << linklist.ListEmpty() << endl;
	linklist.ListDelete(t2, 3);
	linklist.ListDelete(t2, 5);
	linklist.ListDelete(t2, 12);
	linklist.ListDelete(t2, 19);//此时没有19号元素
	linklist.TraverseList();
	for (int i = 1; i <= 20; i++)
	{
		int ind = linklist.locateElem(i * 3);
		if (ind)
			cout << i * 3 << "是第" << ind << "个" << endl;
		else
			cout << "未找到" << i * 3 << "该元素" << endl;
	}
}