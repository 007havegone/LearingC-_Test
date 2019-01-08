#include "Tree.h"
Tree::Tree()
{
	m_pRoot = new Node();//创建一棵树，一个根节点
}

Tree::~Tree()//销毁树
{
	//DeleteNode(0, NULL);效果相同
	m_pRoot->DeleteNode();
}

Node * Tree::searchNode(int nodeIndex)
{
	return m_pRoot->searchNode(nodeIndex);
}

bool Tree::AddNode(int nodeIndex, int direction,const Node* node)
{
	Node *temp = searchNode(nodeIndex);//查找添加位置
	if (temp == NULL)
	{
		return false;
	}
	Node *mnode = new Node();//新建结点
	mnode->index = node->index;
	mnode->data = node->data;
	mnode->pParent = temp;
	if (direction == 0)//左子树
	{
		temp->pLChile = mnode;
	}
	if (direction == 1)//右子树
	{
		temp->pRChile = mnode;
	}
	return true;
}

bool Tree::DeleteNode(int nodeIndex, Node* node)
{
	Node* temp = searchNode(nodeIndex);//查找删除的结点
	if (temp == NULL)
	{
		return false;
	}
	if (node != NULL)
	{
		node->data = temp->data;//将删除结点拷贝出去
	}
	temp->DeleteNode();//调用Node类的删除函数完成其余工作
	return true;
}
//递归版
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
//非递归版
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



