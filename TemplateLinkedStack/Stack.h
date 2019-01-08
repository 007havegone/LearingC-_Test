#ifndef  STACK_H_
#define  STACK_H_

#include <iostream>


template<typename T>
class LinkedStack
{
public:
	typedef struct sNode
	{
		T data;
		sNode* next;
	}sNode;
	LinkedStack();
	~LinkedStack();
	bool isEmpty();	
	bool push(T t);// void push();抛出异常处理
	bool pop(T &t);// T& pop();
	bool top(T &t);// T& top();
private:
	sNode *ptop;
	int size;
};
template<typename T>
inline LinkedStack<T>::LinkedStack()
{
	size = 0;
	ptop = nullptr;
}

template<typename T>
inline LinkedStack<T>::~LinkedStack()
{
	sNode * t;
	while (ptop)
	{
		t= ptop;
		ptop = ptop->next;
		delete t;
	}
	size = 0;
}

template<typename T>
inline bool LinkedStack<T>::isEmpty()
{
	return size == 0;
}

template<typename T>
inline bool LinkedStack<T>::push(T t)
{
	sNode *n = new sNode();
	n->data = t;
	n->next = ptop;
	ptop = n;
	size++;
	return true;
}

template<typename T>
inline bool LinkedStack<T>::pop(T & t)
{
	if (size == 0)
		return false;
	sNode *p = ptop;
	ptop = ptop->next;
	t = p->data;
	delete p;
	size--;
	return true;
}

template<typename T>
inline bool LinkedStack<T>::top(T & t)
{
	if (size == 0)
		return false;
	t = ptop->data;
	return true;
}



#endif // ! STACK_H_
