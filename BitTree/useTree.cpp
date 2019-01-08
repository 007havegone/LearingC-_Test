#include "BitTree.h"
#include <iostream>
using namespace std;

/*
树 t1
			1
		  /    \
		2		3
	  /    \
	4		5
			/\
		  6	  7

输入：
1 2 4 -1 -1 5 6 7 -1 -1 -1 -1 3 -1 -1
先序 1 2 4 5 6 7 3
中序 4 2 6 5 7 1 3
后续 4 6 7 5 2 3 1
树 t2
			1
		  /    \
		2		3
	  /    \
	4		5
			/\
		  6	  7
		  /\
		1	2

输入：
1 2 4 -1 -1 5 6  1 -1 -1 2 -1 -1 7 -1 -1 3 -1 -1
先序 1 2 4 5 6 1 2 7 3
中序 4 2 1 6 2 5 7 3 1
后序 4 1 2 6 7 5 2 3 1
树 t3

				6
			   / \
			 3     9
		   /  \	   / \
		 1     4   7   10
		  \		\	\	\
		  2		 5	 8	  11

输入：
6 3 1 -1 2 -1 -1 4 -1 5 -1 -1 9 7 -1 8 -1 -1 10 -1 11 -1 -1
先序 6 3 1 2 4 5 9 7 8 10 11
中序 1 2 3 4 5 6 7 8 9 10 11
后序 2 1 5 4 3 8 7 11 10 9 6

*/
int main()
{
	BitTree t1;
	BitTree t2;
	CreateBitTree(t1);
	CopyTree(t1, t2);
	cout << "树t1的结点个数：" << NodeCount(t1) << endl;
	cout << "树t1的深度：" << TreeDepth(t1) << endl;
	cout << "树t1的叶子结点数：" << LeavesCount(t1) << endl;
	cout << "t1==t2 ?  " << equal(t1, t2) << endl;
	cout << "先序：";
	PreOrderTraverse(t1);
	cout << endl;
	cout << "中序：";
	InOrderTraverse(t1);
	cout << endl;
	cout << "后序：";
	PostOrderTraverse(t1);
	cout << endl;
	BitNode *res = getLoca(t1, 5);
	if (res)
		cout << "成功找到结点元素为5" << endl;
	else
		cout << "未找到该结点" << endl;
	EchangeLRchile(t1);
	cout << "\n\n交换后\n";
	cout << "先序：";
	PreOrderTraverse(t1);
	cout << endl;
	cout << "中序：";
	InOrderTraverse(t1);
	cout << endl;
	cout << "先后：";
	PostOrderTraverse(t1);
	cout << endl;

	DestoryTree(t1);
	if (!t1)
		cout << "销毁成功" << endl;
	return 0;
}