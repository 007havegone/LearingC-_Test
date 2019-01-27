#include "MinHeap.h"
#include "MaxHeap.h"
#include <iostream>
#include <vector>
using namespace std;

int main()
{
	vector<int> vec{ 5,4,1,2,3,6 };
	MaxHeap h1{ vec };
	h1.MaxHeapPrint(); cout << endl;
	h1.MaxHeapSort();
	h1.MaxHeapPrint(); cout << endl;
}