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
		Node* t=this->pLChile->searchNode(nodeIndex);//左子树查找
		if (t)
			return t;
	}
	if (this->pRChile)
	{
		Node *t=this->pRChile->searchNode(nodeIndex);//右子树查找
		if (t)
			return t;
	}
	//都未找到，返回空
	return NULL;
}

void Node::DeleteNode()
{
	//递归删除左右结点
	if (this->pLChile)
	{
		this->pLChile->DeleteNode();
	}
	if (this->pRChile)
	{
		this->pRChile->DeleteNode();
	}
	//修改父节点指针域
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
	//释放该结点内存
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
	while (p || !sta.empty())//当前层或还有上层未空
	{
		if (p)
		{
			bepush[p] = 1;//第一次压入
			sta.push(p);
			p = p->pLChile;//进入左子树
		}
		else
		{
			t = sta.top();//获取栈顶结点
			if (!t->pRChile)//终端结点
			{
				cout << t->index << " " << t ->data << endl;
				sta.pop();
				p = t->pRChile;//置为空
			}
			else
			{
				if (bepush[t] == 1)//标记该根节点，进入右子树
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
