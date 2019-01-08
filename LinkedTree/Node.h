#ifndef NODE_H_
#define NODE_H_
#include <iostream>
class Node
{
	
public:
	Node();								//构造函数
	Node *searchNode(int nodeIndex);	//查找结点
	void DeleteNode();					//删除结点
	void PreorderTraverse();			//先序遍历
	void InorderTraverse();				//中序遍历
	void PostorderTraverse();			//后序遍历
	void RePreorderTraverse();			//非递归先序遍历
	void ReInorderTraverse();			//非递归中序遍历
	void RePostorderTraverse();			//非递归后序遍历
	int index;							//下标
	int data;							//数据
	Node *pLChile;						//左孩子指针
	Node *pRChile;						//右孩子指针
	Node *pParent;						//双亲指针
};
#endif // !NODE_H_
