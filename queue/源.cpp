#include <iostream>
#include <queue>
#include <iterator>
#include <algorithm>
#include <ctime>
#include <random>
using namespace std;

int main()
{
	srand(time(0));
	priority_queue<int,vector<int>,greater<int> > a;
	for (int i = 0; i < 10; i++)
		a.push(rand() % 15);
	while (!a.empty())
	{
		cout << a.top() << " ";
		a.pop();
	}
	cout << endl;
}