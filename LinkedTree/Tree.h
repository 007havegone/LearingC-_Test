#ifndef TREE_H_
#define TREE_H_

#include "Node.h"
#include <iostream>
/*
	ʵ�ֹ��ܣ�
	1�����ҽ��			2����ӽ��
	3��ɾ�����			4�����ֱ�����ʽ���ݹ�+�ǵݹ飩
*/
class Tree 
{
public:
	Tree();															//������
	~Tree();														//������
	Node* searchNode(int nodeIndex);								//�������
	bool AddNode(int nodeIndex, int direction, const Node* node);	//��ӽ��
	bool DeleteNode(int nodeIndex, Node *node);						//ɾ�����
	void PreorderTraverse();										//ǰ������
	void InorderTraverse();											//��������
	void PostorderTraverse();										//��������
	void RePreorderTraverse();										//�ǵݹ��������
	void ReInorderTraverse();										//�ǵݹ��������
	void RePostorderTraverse();										//�ǵݹ�������
private:
	Node *m_pRoot;													//��ָ��
};
#endif // !TREE_H_


