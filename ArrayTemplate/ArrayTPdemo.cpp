#include "ArrayTemplate.h"
#include <iostream>

int main()
{
	using std::cout;
	using std::endl;
	ArrayTP<int, 10> sum;
	ArrayTP<double, 10> aves;
	ArrayTP< ArrayTP<int, 5>, 10> twodee;

	int i, j;
	for (int i = 0; i < 10; i++)
	{
		sum[i] = 0;
		for (int j = 0; j < 5; j++)
		{
			twodee[i][j] = (i + 1)*(j + 1);
			sum[i] += twodee[i][j];
		}
		aves[i] = (double)sum[i] / 10;
	}
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			cout.width(2);
			cout << twodee[i][j] << " ";
		}
		cout << ": sum = ";
		cout.width(3);
		cout << sum[i] << ", average = " << aves[i] << endl;
	}
	cout << "Done,\n";
	return 0;
}
