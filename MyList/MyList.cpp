#include "MyList.h"
#include <iostream>

ArrayList::ArrayList(int size)
{
	if (size > MAXSIZE)
		size = MAXSIZE;
	limitsize = size;
	elemts = new int[size];
	listsize = 0;
}

ArrayList::ArrayList():ArrayList(MAXSIZE){}

ArrayList::~ArrayList()
{
	std::cout << "List is destory!!!" << std::endl;
	listsize = 0;
	delete[]elemts;
}

Statu ArrayList::Insert(int num, int i)
{
	if (isFull())
	{
		std::cout << "线性表已满" << std::endl;
		return ERROR;
	}
	if (i<1 || i>listsize + 1)
	{
		std::cout << "插入为序不合法" << std::endl;
		return ERROR;
	}
	for (int j = listsize; j >= i; j--)
		elemts[j] = elemts[j - 1];
	elemts[i - 1] = num;
	listsize++;
	return OK;
		
}

Statu ArrayList::Delete(int & num, int i)
{
	if (isEmpty())
		return ERROR;
	num = elemts[i - 1];
	for (int j = i; j < listsize; j++)
		elemts[j - 1] = elemts[j];
	listsize--;
	return OK;
}

Statu ArrayList::GetElemt(int & num,int i)
{
	if (i > listsize || isEmpty() || i < 1)
		return ERROR;
	num = elemts[i - 1];
	return OK;
}

Statu ArrayList::Clear()
{
	std::cout << "List is Cleaned." << std::endl;
	listsize = 0;
	return OK;
}

void ArrayList::Show()
{
	if (listsize) {
		for (int i = 0; i < listsize; i++)
			std::cout << elemts[i] << " ";
		std::cout << '\n';
	}
	else
		std::cout<<"该线性表为空\n";
}

bool ArrayList::isEmpty()
{
	return listsize == 0;
}

bool ArrayList::isFull()
{
	return listsize == limitsize;
}

int ArrayList::getSize()
{
	return listsize;
}
