#include "LinkedList.h"
using namespace std;
status CreatLkList(LinkList & L, int n)
{
	L = new LNode;
	L->next = NULL;
	cout << "Input the element value reversing:\n";
	for (int i = 0; i < n; i++)
	{
		LNode* p = new LNode;
		cin >> p->data;
		p->next = L->next;
		L->next = p;
	}
	cout << "The Linklist as follow:\n";
	cout << "L->";
	LNode * t = L->next;
	while (t)
	{
		cout << t->data << "->";
		t = t->next;
	}
	cout << "NULL";
	return OK;
}

status InsertLkList(LinkList & L, int i, ElemType e)
{
	LNode *p = L;
	int j = 0;
	while (p&&j < i - 1)
	{
		p = p->next;
		j++;
	}
	if (!p || j > i - 1)
		return ERROR;
	LNode* t = new LNode;
	t->data = e;
	t->next = p->next;
	p->next = t;
	return OK;
}

status DeleteLkList(LinkList & L, int i)
{
	LNode* p = L;
	int j = 0;
	while (p->next&&j < i - 1)
	{
		p = p->next;
		j++;
	}
	if (!p->next || j > i - 1)
	{
		cout << "\nThe value of i is out of bounds!\n";
		return ERROR;
	}
	LNode* t = p->next;
	p->next = t->next;
	delete t;
	return OK;

}

status DeleteLkList(LinkList & L, ElemType mmin, ElemType mmax)
{
	LNode *pre = L;//初始头节点，修改前驱
	LNode *now = pre->next;//当前工作指针
	LNode *t;//临时缓存
	while (now && now->data < mmax)//因升序，大于mmax提前跳出
	{
		if (now->data > mmin&&now->data < mmax)
		{
			t = now;
			now = now->next;
			pre->next = now;
			delete t;
		}
		else {
			pre = pre->next;
			now = now->next;
		}
	}
	return OK;
}

status DestoryLkList(LinkList & L)
{
	LNode* t;
	while (L)
	{
		t = L;//保存头节点
		L = L->next;//改变头指针
		delete t;//删除头节点
	}
	cout << "\nThe LinkList is Destoryed!\n";
	return OK;
}
int FindOrInsert(LinkList & L, ElemType x)
{
	int i = 0;
	LNode *pre = L;
	LNode *now = pre->next;
	while (now && now->data <= x)
	{
		if (now->data == x)//找到返回位序
			return i;
		now = now->next;
		pre = pre->next;
		i++;
	}
	LNode *t = new LNode;
	t->data = x;
	t->next = now;
	pre->next = t;
	cout << "未找到 " << x << " 将其插入成功!\n";
	return 0;//失败返回位序0
}

LNode * reverseList(LinkList & L, int flag)//flag当前是否指向头结点标签
{
	if (!L->next || (!L->next->next && flag==1))//空表或一个元素
		return NULL;
	if (!L->next->next)//递归出口
	{
		LNode *tair = L->next;
		tair->next = L;
		L->next = NULL;
		return tair;//返回尾节点
	}
	else
	{
		LNode* tair=reverseList(L->next, 0);
		if (flag)//指向头结点
		{
			L->next->next = NULL;//原首元结点指向空
			L->next = tair;//头结点指向原尾结点
		}
		else
		{
			L->next->next = L;
			L->next = NULL;
		}
		return tair;
	}
}

ostream & operator<<(ostream & os, LinkList L)
{
	LNode * p = L->next;
	if (!p) {
		os << "The empty LinkedList" << endl;
		return os;
	}
	cout << "L->";
	while (p)
	{
		os << p->data << "->";
		p = p->next;
	}
	os << "NULL";
	return os;
}
