#include "Node.h"
#include <map>
#include <stack>
using namespace std;
Node::Node()
{
	index = 0;
	data = 0;
	pLChile = NULL;
	pRChile = NULL;
	pParent = NULL;
}

Node * Node::searchNode(int nodeIndex)
{
	if (this->index == nodeIndex)
	{
		return this;
	}
	if (this->pLChile)
	{
		Node* t=this->pLChile->searchNode(nodeIndex);//����������
		if (t)
			return t;
	}
	if (this->pRChile)
	{
		Node *t=this->pRChile->searchNode(nodeIndex);//����������
		if (t)
			return t;
	}
	//��δ�ҵ������ؿ�
	return NULL;
}

void Node::DeleteNode()
{
	//�ݹ�ɾ�����ҽ��
	if (this->pLChile)
	{
		this->pLChile->DeleteNode();
	}
	if (this->pRChile)
	{
		this->pRChile->DeleteNode();
	}
	//�޸ĸ��ڵ�ָ����
	if (this->pParent != NULL)
	{
		if (this->pParent->pLChile == this)
		{
			this->pParent->pLChile = NULL;
		}
		if (this->pParent->pRChile == this)
		{
			this->pParent->pRChile = NULL;
		}
	}
	//�ͷŸý���ڴ�
	delete this;
}

void Node::PreorderTraverse()
{
	cout << this->index << " " << this->data << endl;
	if (this->pLChile != NULL)
		this->pLChile->PreorderTraverse();
	if (this->pRChile != NULL)
		this->pRChile->PreorderTraverse();

}

void Node::InorderTraverse()
{
	if (this->pLChile != NULL)
		this->pLChile->InorderTraverse();
	cout << this->index << " " << this->data << endl;
	if (this->pRChile != NULL)
		this->pRChile->InorderTraverse();
}

void Node::PostorderTraverse()
{
	if (this->pLChile != NULL)
		this->pLChile->PostorderTraverse();
	if (this->pRChile != NULL)
		this->pRChile->PostorderTraverse();
	cout << this->index << " " << this->data << endl;
}

void Node::RePreorderTraverse()
{
	stack<Node*> sta;
	Node* p = this;
	Node* t;
	while (p || !sta.empty())
	{
		if (p)
		{
			cout << p->index << " " << p->data << endl;
			sta.push(p);
			p = p->pLChile;
		}
		else
		{
			t = sta.top();
			sta.pop();
			p = t->pRChile;
		}
	}
}

void Node::ReInorderTraverse()
{
	stack<Node*> sta;
	Node* t;
	Node* p = this;
	while (p || !sta.empty())
	{
		if (p)
		{
			sta.push(p);
			p = p->pLChile;
		}
		else
		{
			t = sta.top();
			sta.pop();
			cout << t->index << " " << t->data << endl;
			p = t->pRChile;
		}
	}
}

void Node::RePostorderTraverse()
{
	stack<Node*> sta;
	map<Node*, int> bepush;
	Node *p = this;
	Node* t;
	while (p || !sta.empty())//��ǰ������ϲ�δ��
	{
		if (p)
		{
			bepush[p] = 1;//��һ��ѹ��
			sta.push(p);
			p = p->pLChile;//����������
		}
		else
		{
			t = sta.top();//��ȡջ�����
			if (!t->pRChile)//�ն˽��
			{
				cout << t->index << " " << t ->data << endl;
				sta.pop();
				p = t->pRChile;//��Ϊ��
			}
			else
			{
				if (bepush[t] == 1)//��Ǹø��ڵ㣬����������
				{
					bepush[t] = 2;
					p = t->pRChile;
				}
				else if(bepush[t]==2)//
				{
					cout << t->index << " " << t->data << endl;
					sta.pop();

					p = NULL;
				}
			}

		}
	}
}
