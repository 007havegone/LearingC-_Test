#include "ArrayList.h"
#include <iostream>
#include <random>
using namespace std;
int main()
{
	ArrayList<int> intarr;
	for (int i = 0; i < 10; i++)
	{
		intarr.ListInsert(i + 10, i+1);
	}
	intarr.TraverseList();
	int d1;
	int d2;
	intarr.ListDelete(d1, 1);
	intarr.ListDelete(d2, 9);
	intarr.ListDelete(d1, 2);
	intarr.ListInsert(200, 2);
	intarr.ListInsert(800, 8);
	intarr.getElements(1, d1);
	intarr.TraverseList();
	cout << "Elements9 = " << d1 << endl;
	cout << intarr.getLength() << endl;
}