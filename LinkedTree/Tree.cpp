#include "Tree.h"
Tree::Tree()
{
	m_pRoot = new Node();//����һ������һ�����ڵ�
}

Tree::~Tree()//������
{
	//DeleteNode(0, NULL);Ч����ͬ
	m_pRoot->DeleteNode();
}

Node * Tree::searchNode(int nodeIndex)
{
	return m_pRoot->searchNode(nodeIndex);
}

bool Tree::AddNode(int nodeIndex, int direction,const Node* node)
{
	Node *temp = searchNode(nodeIndex);//�������λ��
	if (temp == NULL)
	{
		return false;
	}
	Node *mnode = new Node();//�½����
	mnode->index = node->index;
	mnode->data = node->data;
	mnode->pParent = temp;
	if (direction == 0)//������
	{
		temp->pLChile = mnode;
	}
	if (direction == 1)//������
	{
		temp->pRChile = mnode;
	}
	return true;
}

bool Tree::DeleteNode(int nodeIndex, Node* node)
{
	Node* temp = searchNode(nodeIndex);//����ɾ���Ľ��
	if (temp == NULL)
	{
		return false;
	}
	if (node != NULL)
	{
		node->data = temp->data;//��ɾ����㿽����ȥ
	}
	temp->DeleteNode();//����Node���ɾ������������๤��
	return true;
}
//�ݹ��
void Tree::PreorderTraverse()
{
	m_pRoot->PreorderTraverse();
}

void Tree::InorderTraverse()
{
	m_pRoot->InorderTraverse();
}

void Tree::PostorderTraverse()
{
	m_pRoot->PostorderTraverse();
}
//�ǵݹ��
void Tree::RePreorderTraverse()
{
	m_pRoot->RePreorderTraverse();
}

void Tree::ReInorderTraverse()
{
	m_pRoot->ReInorderTraverse();
}

void Tree::RePostorderTraverse()
{
	m_pRoot->RePostorderTraverse();
}



