#pragma once
#include <vector>
#include <algorithm>
#include <iostream>
class MinHeap {

private:
	std::vector<int> vec;
	size_t cnt;
	const static int StartInex = 1;//从1开始存放

	void MinHeapMakeHeap();
	void shiftDown(int index);
	void shiftUp(int child);
public:
	MinHeap();
	MinHeap(std::vector<int> data);
	void MinHeapPop();
	void MinHeapPush(int i);
	//调用后从大到小排列，不再具有小根堆特性,或者传入一个返回一个vec
	void MinHeapSort();
	void MinHeapPrint();
	int top() {
		return vec[StartInex];
	}
};
