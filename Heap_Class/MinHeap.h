#pragma once
#include <vector>
#include <algorithm>
#include <iostream>
class MinHeap {

private:
	std::vector<int> vec;
	size_t cnt;
	const static int StartInex = 1;//��1��ʼ���

	void MinHeapMakeHeap();
	void shiftDown(int index);
	void shiftUp(int child);
public:
	MinHeap();
	MinHeap(std::vector<int> data);
	void MinHeapPop();
	void MinHeapPush(int i);
	//���ú�Ӵ�С���У����پ���С��������,���ߴ���һ������һ��vec
	void MinHeapSort();
	void MinHeapPrint();
	int top() {
		return vec[StartInex];
	}
};
