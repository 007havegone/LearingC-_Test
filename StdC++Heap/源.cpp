#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	int arr[] = { 5,4,1,2,3,6 };
	//默认大根堆
	//make_heap(arr, arr + 6);
	//小根堆
	make_heap(arr, arr + 6, greater<int>());
	for (auto i : arr)
		cout << i << " ";
	cout << endl;
	size_t t = sizeof(arr) / sizeof(int);
	for (int i = 0; i < t; i++)
	{
		cout << arr[0] << " ";
		pop_heap(arr, arr + t - i);
	}
	cout << endl;

	cout << "vector的样例" << endl;
	vector<int> vec = { 5,4,3,1,2,6 };
	make_heap(vec.begin(), vec.end(), less<int>());//大根堆
	vec.push_back(100);
	for (auto i : vec)
	{
		cout << i << " ";
	}
	push_heap(vec.begin(), vec.end());
	cout << endl;
	//堆排序等价于sort_heap
	size_t s = vec.size();
	//for (int i = 0; i < s-1; i++)
	//{
	//	pop_heap(vec.begin(), vec.end() - i);
	//}
	//for (auto i : vec)
	//	cout << i << " ";
	//while (!vec.empty())
	//{
	//	cout << vec[0] << " ";
	//	pop_heap(vec.begin(), vec.end());
	//	//cout << vec.back() << " ";
	//	vec.pop_back();
	//}
	//sort_heap(vec.begin(), vec.end());
	
}
