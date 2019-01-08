#include "Stack.h"
#include <iostream>

template <template <typename T> class Thing>
class Crab
{
private:
	Thing<int> s1;
	Thing<double> s2;
public:
	Crab() {};
	bool push(int a,double x)
	{
		return s1.push(a) && s2.push(x);
	}
	bool pop(int &a, double &b)
	{
		return s1.pop(a) && s2.pop(b);
	}
};
int main()
{
	using std::cout;
	using std::cin;
	using std::endl;
	Crab<Stack> nebula;
	//Stack must match template <typename T> class thing
	int ni;
	double nb;
	cout << "Enter the double pairs, such as 4 3.5(0 0 to end):\n";
	while (cin >> ni >> nb && (ni > 0 || nb > 0))
	{
		if (!nebula.push(ni, nb))
			break;
	}
	while (nebula.pop(ni, nb))
		cout << ni << " , " << nb << endl;
	cout << "Done" << endl;
	return 0;
}