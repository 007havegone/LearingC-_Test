#include "MinHeap.h"

void MinHeap::MinHeapMakeHeap()
{
	int n = cnt;
	for (int i = n >> 1; i >= StartInex; i--)
	{
		shiftDown(i);
	}
}

void MinHeap::shiftDown(int index)
{
	int tmp = vec[index];
	int lchild = index << 1;
	while (lchild <= cnt)
	{
		if (lchild + 1 <= cnt && vec[lchild + 1] < vec[lchild])
			lchild++;
		if (vec[lchild] >= tmp)
			break;
		else
			vec[index] = vec[lchild];
		index = lchild;
		lchild <<= 1;
	}
	vec[index] = tmp;
}

MinHeap::MinHeap()
{
	vec.clear();
	cnt = 0;
	vec.push_back(0);
}

MinHeap::MinHeap(std::vector<int> data)
{
	vec.clear();
	vec.push_back(0);
	int sz = data.size();
	for (int i = 0; i < sz; i++)
		vec.push_back(data[i]);
	cnt = sz;
	MinHeapMakeHeap();
}

void MinHeap::MinHeapPop()
{
	vec[StartInex] = vec[cnt];
	cnt--;
	shiftDown(StartInex);
	vec.pop_back();
}

void MinHeap::MinHeapPush(int i)
{
	vec.push_back(i);
	cnt++;
	shiftUp(cnt);
}

void MinHeap::MinHeapSort()
{
	int sz = cnt;
	for (int i = 0; i < sz - 1; i++)
	{
		int temp = vec[StartInex];
		MinHeapPop();
		vec[cnt + 1] = temp;
	}
	cnt += (sz - 1);
}

void MinHeap::MinHeapPrint()
{
	for (int i = StartInex; i <= cnt; i++)
		std::cout << vec[i] << " ";
}

void MinHeap::shiftUp(int child)
{
	int tmp = vec[child];
	int parent = tmp << 1;
	while (parent >= StartInex && child != StartInex) {
		if (vec[parent] <= tmp)
			break;
		else
		{
			vec[child] = vec[parent];
			child = parent;
			parent >>= 1;
		}
	}
	vec[child] = tmp;
}
