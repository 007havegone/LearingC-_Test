#ifndef NODE_H_
#define NODE_H_
#include <iostream>
class Node
{
	
public:
	Node();								//���캯��
	Node *searchNode(int nodeIndex);	//���ҽ��
	void DeleteNode();					//ɾ�����
	void PreorderTraverse();			//�������
	void InorderTraverse();				//�������
	void PostorderTraverse();			//�������
	void RePreorderTraverse();			//�ǵݹ��������
	void ReInorderTraverse();			//�ǵݹ��������
	void RePostorderTraverse();			//�ǵݹ�������
	int index;							//�±�
	int data;							//����
	Node *pLChile;						//����ָ��
	Node *pRChile;						//�Һ���ָ��
	Node *pParent;						//˫��ָ��
};
#endif // !NODE_H_
