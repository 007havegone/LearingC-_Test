#pragma once
#include <vector>
class MaxHeap
{
public:
	MaxHeap();
	MaxHeap(const std::vector<int>& vec);
	void MaxHeapPush(int i);//添加
	void MaxHeapPop();//弹出
	void MaxHeapPrint();
	void MaxHeapSort();//实现非递减排序
	int top() {
		return data[StartIndex];
	}
private:
	const static int StartIndex = 1;//从1开始下标
	size_t cnt;//数量
	std::vector<int> data;//底层数组
	//创建堆
	void MaxHeapMake();
	//上溯
	void shiftUp(int index);
	//下调
	void shiftDown(int index);
};



