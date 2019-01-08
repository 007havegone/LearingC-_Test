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
	LNode *pre = L;//��ʼͷ�ڵ㣬�޸�ǰ��
	LNode *now = pre->next;//��ǰ����ָ��
	LNode *t;//��ʱ����
	while (now && now->data < mmax)//�����򣬴���mmax��ǰ����
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
		t = L;//����ͷ�ڵ�
		L = L->next;//�ı�ͷָ��
		delete t;//ɾ��ͷ�ڵ�
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
		if (now->data == x)//�ҵ�����λ��
			return i;
		now = now->next;
		pre = pre->next;
		i++;
	}
	LNode *t = new LNode;
	t->data = x;
	t->next = now;
	pre->next = t;
	cout << "δ�ҵ� " << x << " �������ɹ�!\n";
	return 0;//ʧ�ܷ���λ��0
}

LNode * reverseList(LinkList & L, int flag)//flag��ǰ�Ƿ�ָ��ͷ����ǩ
{
	if (!L->next || (!L->next->next && flag==1))//�ձ��һ��Ԫ��
		return NULL;
	if (!L->next->next)//�ݹ����
	{
		LNode *tair = L->next;
		tair->next = L;
		L->next = NULL;
		return tair;//����β�ڵ�
	}
	else
	{
		LNode* tair=reverseList(L->next, 0);
		if (flag)//ָ��ͷ���
		{
			L->next->next = NULL;//ԭ��Ԫ���ָ���
			L->next = tair;//ͷ���ָ��ԭβ���
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
