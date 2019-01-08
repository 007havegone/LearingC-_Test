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
	enum{ERROR,OVER_FLOW,OK};//去掉iostream头文件后不报错
	struct Node//定义节点
	{
		T data;
		Node *next;
		Node(const T& t):data(t), next() {}//data置为t，next置为NULL
		Node():next(0) {}
	};
	Node* Nptr;//定义头指针
	LinkedList(const LinkedList& ll):length(0),Nptr(0){ }
	LinkedList& operator=(const LinkedList& ll) { return *this; }
public:
	LinkedList()
	{
		Nptr = new Node();//创建头节点,data未初始化
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
inline LinkedList<T>::~LinkedList()//将整个链表清空
{
	Node* t = Nptr;//获取头节点
	while (Nptr)//直到头节点为空
	{
		Nptr = Nptr->next;
		delete t;
		t = Nptr;
	}
	length = 0;
}

template<typename T>
inline Status LinkedList<T>::ClearList()//将头节点后的清空
{
	Node* t = Nptr->next;//获取首元节点
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
	Node* p = Nptr;//获取头节点
	int j = 0;
	while (p&&j < n)
	{
		p = p->next;
		j++;
	}
	if (!p || j > n)//n>length+1或者n<1
		return ERROR;
	t = p->data;
	return OK;
}

template<typename T>
inline Status LinkedList<T>::PriorElem(T cur, T & pre)
{
	Node* pr = Nptr;//头节点
	Node* now = Nptr->next;//首元节点
	while (now&&now->data != cur)
	{
		pr = now;
		now = now->next;
	}
	if (!now || pr = Nptr)//没匹配到或者是第一个节点
		return ERROR;
	pre = pr->data;
	return OK;
}

template<typename T>
inline Status LinkedList<T>::NextElem(T cur, T & next)
{
	Node* now = Nptr;//头节点
	Node* n = Nptr->next;//首元节点
	while (n&&now->data != cur)//直到没有下一个节点同时没匹配到
	{
		n = n->next;
		now = n;
	}
	if (!n)//下一个节点为空,即匹配失败
		return ERROR;
	next = n->data;
	return OK;
}

template<typename T>
inline Status LinkedList<T>::ListInsert(T t, int i)
{
	int j = 0;
	Node* p = Nptr;
	while (p&&j < i - 1)//定位到i-1节点
	{
		p = p->next;
		j++;
	}
	if (!p || j > i - 1)
		return ERROR;//j>length或者i<1
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
	while (p->next&&j < i - 1)//定位到第i-1个节点
	{
		p = p->next;
		j++;
	}
	if (!(p->next) || j > i - 1)//不存在第i节点或者i<1
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
		cout << "当前链表为空" << endl;
	}
	Node* n = Nptr->next;//首元节点
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
	Node* p = Nptr->next;//首元节点
	int j = 1;//第一个
	while (p&&p->data != t)//当前节点未空且不匹配
	{
		p = p->next;
		j++;
	}
	if (!p || j > length)
		return 0;
	return j;
}
