#pragma once
#include <iostream>
using std::end;
using std::cout;
typedef int Status;
template <typename T>
class ArrayList
{
private:
	T * elements;//T为指针类型类外具体化模板
	int len;
	const int MAXNSIZE=10;
	enum{ERROR,OVER_FOLW,OK};
	//将复制构造函数和赋值运算符私有化
	ArrayList(const ArrayList& arrlist) { elements = NULL; len = 0; };
	ArrayList& operator=(const ArrayList& arrlist) { return *this; }
public:
	ArrayList();//constructor
	~ArrayList();//destructor
	Status ClearList();//clear the list;
	bool ListEmpty()const;
	int getLength()const;
	Status getElements(int n,T& t);
	int locateElem(T t)const;//存在返回下标，不存在返回0
	Status PriorElem(T cur, T& pre);
	Status NextElem(T cur, T& next);
	Status ListInsert(T t, int i);//第i个位置插入元素t
	Status ListDelete(T& t,int i);
	void TraverseList()const;
};

template<typename T>
inline ArrayList<T>::ArrayList()
{
	elements = new T[MAXNSIZE];
	if (!elements)
		exit(OVER_FOLW);
	len = 0;
}

template<typename T>
inline ArrayList<T>::~ArrayList()
{
	delete[] elements;
	len = 0;
	elements = NULL;
}

template<typename T>
inline Status ArrayList<T>::ClearList()
{
	len = 0;
	return OK;
}

template<typename T>
inline bool ArrayList<T>::ListEmpty()const
{
	return len==0;
}

template<typename T>
inline int ArrayList<T>::getLength()const
{
	return len;
}


template<typename T>
inline int ArrayList<T>::locateElem(T t) const
{
	for (int i = 0; i < len; i++)
		if (t == elements[i])
			return i + 1;;
	return 0;
}

template<typename T>
inline Status ArrayList<T>::PriorElem(T cur, T & pre)
{
	for(int i=0;i<len;i++)
		if (elements[i] == cur && i != 0)
		{
			pre[i - 1];
			return OK;
		}
	return ERROR;
}

template<typename T>
inline Status ArrayList<T>::NextElem(T cur, T & next)
{
	for(int i=0;i<len-1;i++)
		if (elements[i] == cur)
		{
			next = elements[i + 1];
			return OK;
		}
	return ERROR;
}

template<typename T>
inline Status ArrayList<T>::ListInsert(T t, int i)
{
	if (i<1 || i>len + 1)
		return ERROR;
	for (int j = len; j >= i; j--)
		elements[j] = elements[j - 1];
	elements[i - 1] = t;
	len++;
	return OK;

}

template<typename T>
inline Status ArrayList<T>::ListDelete(T & t,int i)
{
	if (i > len || i < 1)
		return ERROR;
	for (; i < len-1; i++)
		elements[i - 1] = elements[i];
	len--;
	return OK;
}

template<typename T>
inline void ArrayList<T>::TraverseList() const
{
	for (int i = 0; i < len; i++)
	{
		cout << i+1 << ":" <<elements[i] << "  ";
		if ((i+1) % 5 == 0)
			cout << endl;
	}
	cout << endl;
}

template<typename T>
inline Status ArrayList<T>::getElements(int n,T& t)
{
	if (n<1 || n>len)
		return ERROR;
	t = elements[n - 1];
	return OK;
}
