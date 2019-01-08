#include <iostream>
#include <iterator>
using namespace std;

int main()
{
	int arr[3][4] = { 1,2,3,4,5,6,7,8,9,10,11,12 };

	for (int (&ar)[4] : arr)
	{
		for (int &a: ar)
			cout << a << " ";
		cout << endl;
	}
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 4; j++)
			cout << arr[i][j] << " ";
		cout << endl;
	}
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 4; j++)
			cout << *(*(arr + i) + j) << " ";
		cout << endl;
	}
			
}