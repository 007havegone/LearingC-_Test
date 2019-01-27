#pragma once
#include <vector>
class MaxHeap
{
public:
	MaxHeap();
	MaxHeap(const std::vector<int>& vec);
	void MaxHeapPush(int i);//���
	void MaxHeapPop();//����
	void MaxHeapPrint();
	void MaxHeapSort();//ʵ�ַǵݼ�����
	int top() {
		return data[StartIndex];
	}
private:
	const static int StartIndex = 1;//��1��ʼ�±�
	size_t cnt;//����
	std::vector<int> data;//�ײ�����
	//������
	void MaxHeapMake();
	//����
	void shiftUp(int index);
	//�µ�
	void shiftDown(int index);
};



