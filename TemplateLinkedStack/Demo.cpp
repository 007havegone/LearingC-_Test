#include "Stack.h"
using namespace std;
int main()
{
	LinkedStack<int> *a = new LinkedStack<int>();
	a->push(11);
	a->push(22);
	a->push(33);

	int t;
	while (!a->isEmpty())
	{
		a->pop(t);
		cout << t << " ";
	}
	cout << a->isEmpty() << endl;

	
}