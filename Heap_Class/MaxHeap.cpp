#include "MaxHeap.h"
#include <iostream>
#include <algorithm>
MaxHeap::MaxHeap()
{
	data.clear();
	cnt = 0;
	data.push_back(0);
}

MaxHeap::MaxHeap(const std::vector<int>& vec)
{
	data.clear();
	data.push_back(0);
	size_t sz = vec.size();
	cnt = sz;
	//添加
	for (size_t i = 0; i < sz; i++)
		data.push_back(vec[i]);
	MaxHeapMake();
}

void MaxHeap::MaxHeapPush(int i)
{
	//添加
	data.push_back(i);
	cnt++;
	shiftUp(cnt);
}

void MaxHeap::MaxHeapPop()
{
	data[StartIndex] = data[cnt];
	cnt--;
	shiftDown(StartIndex);
	data.pop_back();
}

void MaxHeap::MaxHeapPrint()
{
	for (int i = StartIndex; i <= cnt; i++)
		std::cout << data[i] << " ";
}

void MaxHeap::MaxHeapSort()
{
	size_t t = cnt;
	for (int i = 0; i < t-1; i++)
	{
		std::swap(data[StartIndex], data[cnt]);
		cnt--;
		shiftDown(StartIndex);
	}
	cnt += (t - 1);
}

void MaxHeap::MaxHeapMake()
{
	size_t i = cnt;
	for (size_t j = cnt >> 1; j >= StartIndex; j--)
	{
		shiftDown(j);
	}

}

void MaxHeap::shiftUp(int index)
{
	while (index > StartIndex && data[index] > data[index >> 1])
	{
		std::swap(data[index], data[index >> 1]);
		index >>= 1;
	}
}

void MaxHeap::shiftDown(int index)
{
	int lchild = index << 1;
	while (lchild <= cnt)
	{
		//找子树最大
		if (lchild + 1 <= cnt && data[lchild + 1] > data[lchild])
			lchild++;
		if (data[index] >= data[lchild])
			break;
		else
			std::swap(data[index], data[lchild]);
		index = lchild;
		lchild <<= 1;
	}
}
