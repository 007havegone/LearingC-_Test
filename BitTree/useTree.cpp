#include "BitTree.h"
#include <iostream>
using namespace std;

/*
�� t1
			1
		  /    \
		2		3
	  /    \
	4		5
			/\
		  6	  7

���룺
1 2 4 -1 -1 5 6 7 -1 -1 -1 -1 3 -1 -1
���� 1 2 4 5 6 7 3
���� 4 2 6 5 7 1 3
���� 4 6 7 5 2 3 1
�� t2
			1
		  /    \
		2		3
	  /    \
	4		5
			/\
		  6	  7
		  /\
		1	2

���룺
1 2 4 -1 -1 5 6  1 -1 -1 2 -1 -1 7 -1 -1 3 -1 -1
���� 1 2 4 5 6 1 2 7 3
���� 4 2 1 6 2 5 7 3 1
���� 4 1 2 6 7 5 2 3 1
�� t3

				6
			   / \
			 3     9
		   /  \	   / \
		 1     4   7   10
		  \		\	\	\
		  2		 5	 8	  11

���룺
6 3 1 -1 2 -1 -1 4 -1 5 -1 -1 9 7 -1 8 -1 -1 10 -1 11 -1 -1
���� 6 3 1 2 4 5 9 7 8 10 11
���� 1 2 3 4 5 6 7 8 9 10 11
���� 2 1 5 4 3 8 7 11 10 9 6

*/
int main()
{
	BitTree t1;
	BitTree t2;
	CreateBitTree(t1);
	CopyTree(t1, t2);
	cout << "��t1�Ľ�������" << NodeCount(t1) << endl;
	cout << "��t1����ȣ�" << TreeDepth(t1) << endl;
	cout << "��t1��Ҷ�ӽ������" << LeavesCount(t1) << endl;
	cout << "t1==t2 ?  " << equal(t1, t2) << endl;
	cout << "����";
	PreOrderTraverse(t1);
	cout << endl;
	cout << "����";
	InOrderTraverse(t1);
	cout << endl;
	cout << "����";
	PostOrderTraverse(t1);
	cout << endl;
	BitNode *res = getLoca(t1, 5);
	if (res)
		cout << "�ɹ��ҵ����Ԫ��Ϊ5" << endl;
	else
		cout << "δ�ҵ��ý��" << endl;
	EchangeLRchile(t1);
	cout << "\n\n������\n";
	cout << "����";
	PreOrderTraverse(t1);
	cout << endl;
	cout << "����";
	InOrderTraverse(t1);
	cout << endl;
	cout << "�Ⱥ�";
	PostOrderTraverse(t1);
	cout << endl;

	DestoryTree(t1);
	if (!t1)
		cout << "���ٳɹ�" << endl;
	return 0;
}