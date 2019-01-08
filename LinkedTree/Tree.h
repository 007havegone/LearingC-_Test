#ifndef TREE_H_
#define TREE_H_

#include "Node.h"
#include <iostream>
/*
	实现功能：
	1、查找结点			2、添加结点
	3、删除结点			4、三种遍历方式（递归+非递归）
*/
class Tree 
{
public:
	Tree();															//创建树
	~Tree();														//销毁树
	Node* searchNode(int nodeIndex);								//搜索结点
	bool AddNode(int nodeIndex, int direction, const Node* node);	//添加结点
	bool DeleteNode(int nodeIndex, Node *node);						//删除结点
	void PreorderTraverse();										//前序排序
	void InorderTraverse();											//中序排序
	void PostorderTraverse();										//后序排序
	void RePreorderTraverse();										//非递归先序遍历
	void ReInorderTraverse();										//非递归中序遍历
	void RePostorderTraverse();										//非递归后序遍历
private:
	Node *m_pRoot;													//根指针
};
#endif // !TREE_H_


