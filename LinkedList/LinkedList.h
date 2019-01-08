#pragma once
#include <iostream>
using std::cout;
using std::endl;
typedef int Status;
template <typename T>
class LinkedList
{
private:
	int length;
	enum{ERROR,OVER_FLOW,OK};//ȥ��iostreamͷ�ļ��󲻱���
	struct Node//����ڵ�
	{
		T data;
		Node *next;
		Node(const T& t):data(t), next() {}//data��Ϊt��next��ΪNULL
		Node():next(0) {}
	};
	Node* Nptr;//����ͷָ��
	LinkedList(const LinkedList& ll):length(0),Nptr(0){ }
	LinkedList& operator=(const LinkedList& ll) { return *this; }
public:
	LinkedList()
	{
		Nptr = new Node();//����ͷ�ڵ�,dataδ��ʼ��
		if (!Nptr)
			exit(OVER_FLOW);
		length = 0;
	}
	~LinkedList();
	Status ClearList();
	bool ListEmpty()const;
	int getLength()const;
	int locateElem(T t)const;
	Status getElement(int n, T& t)const;
	Status PriorElem(T cur, T& pre);
	Status NextElem(T cur, T& next);
	Status ListInsert(T t, int i);
	Status ListDelete(T& t, int i);
	void TraverseList()const;
};

template<typename T>
inline LinkedList<T>::~LinkedList()//�������������
{
	Node* t = Nptr;//��ȡͷ�ڵ�
	while (Nptr)//ֱ��ͷ�ڵ�Ϊ��
	{
		Nptr = Nptr->next;
		delete t;
		t = Nptr;
	}
	length = 0;
}

template<typename T>
inline Status LinkedList<T>::ClearList()//��ͷ�ڵ������
{
	Node* t = Nptr->next;//��ȡ��Ԫ�ڵ�
	while (t)
	{
		Node* temp = t;
		t = t->next;
		delete temp;
	}
	Nptr->next = NULL;
	length = 0;
	return OK;
}

template<typename T>
inline bool LinkedList<T>::ListEmpty() const
{
	return length == 0;
}

template<typename T>
inline int LinkedList<T>::getLength() const
{
	return length;
}

template<typename T>
inline Status LinkedList<T>::getElement(int n, T & t) const
{
	Node* p = Nptr;//��ȡͷ�ڵ�
	int j = 0;
	while (p&&j < n)
	{
		p = p->next;
		j++;
	}
	if (!p || j > n)//n>length+1����n<1
		return ERROR;
	t = p->data;
	return OK;
}

template<typename T>
inline Status LinkedList<T>::PriorElem(T cur, T & pre)
{
	Node* pr = Nptr;//ͷ�ڵ�
	Node* now = Nptr->next;//��Ԫ�ڵ�
	while (now&&now->data != cur)
	{
		pr = now;
		now = now->next;
	}
	if (!now || pr = Nptr)//ûƥ�䵽�����ǵ�һ���ڵ�
		return ERROR;
	pre = pr->data;
	return OK;
}

template<typename T>
inline Status LinkedList<T>::NextElem(T cur, T & next)
{
	Node* now = Nptr;//ͷ�ڵ�
	Node* n = Nptr->next;//��Ԫ�ڵ�
	while (n&&now->data != cur)//ֱ��û����һ���ڵ�ͬʱûƥ�䵽
	{
		n = n->next;
		now = n;
	}
	if (!n)//��һ���ڵ�Ϊ��,��ƥ��ʧ��
		return ERROR;
	next = n->data;
	return OK;
}

template<typename T>
inline Status LinkedList<T>::ListInsert(T t, int i)
{
	int j = 0;
	Node* p = Nptr;
	while (p&&j < i - 1)//��λ��i-1�ڵ�
	{
		p = p->next;
		j++;
	}
	if (!p || j > i - 1)
		return ERROR;//j>length����i<1
	Node* n = new Node(t);
	n->next = p->next;
	p->next = n;
	length++;
	return OK;
}

template<typename T>
inline Status LinkedList<T>::ListDelete(T & t, int i)
{
	int j = 0;
	Node* p = Nptr;
	while (p->next&&j < i - 1)//��λ����i-1���ڵ�
	{
		p = p->next;
		j++;
	}
	if (!(p->next) || j > i - 1)//�����ڵ�i�ڵ����i<1
		return ERROR;
	Node* q = p->next;
	t = q->data;
	p ->next = q->next;
	delete q;
	length--;
	return OK;
}

template<typename T>
inline void LinkedList<T>::TraverseList() const
{
	if (length < 1)
	{
		cout << "��ǰ����Ϊ��" << endl;
	}
	Node* n = Nptr->next;//��Ԫ�ڵ�
	int i = 0;
	while (n)
	{
		cout << ++i << ":" << n->data<<"   ";
		n = n->next;
	}
	cout << endl;
}

template<typename T>
inline int LinkedList<T>::locateElem(T t) const
{
	Node* p = Nptr->next;//��Ԫ�ڵ�
	int j = 1;//��һ��
	while (p&&p->data != t)//��ǰ�ڵ�δ���Ҳ�ƥ��
	{
		p = p->next;
		j++;
	}
	if (!p || j > length)
		return 0;
	return j;
}
