#include "worker0.h"
#include <iostream>
using std::cin;
using std::cout;
using std::endl;


Worker::~Worker() {}

void Worker::Show()const
{
	cout << "Name:" << fullname << endl;
	cout << "EmployeeID:" << id << endl;
}
void Worker::Set()
{
	cout << "Enter the name of worker:";
	getline(cin, fullname);
	cout << "Enter the ID of worker:";
	cin >> id;
	while (cin.get() != '\n')
		continue;
}

void Waiter::Set()
{
	Worker::Set();
	cout << "Enter panache rating of the waiter:";
	cin >> panache;
	while (cin.get() != '\n')
		continue;
}
void Waiter::Show()const
{
	cout << "Category: Waiter" << endl;
	Worker::Show();
	cout << "Panache rating:" << panache << endl;
}

//初始化Singer的static数组
const char* Singer::pv[] = { "other","alto","contralto",
		"soprano","bass","baritone","tenor" };
void Singer::Set()
{
	Worker::Set();
	cout << "Enter number for singe's vocal range" << endl;
	int i;
	for (i = 0; i < Vtypes; i++)
	{
		cout << i << ":" << pv[i] << " ";
		if (i % 4 == 3)
			cout << endl;
	}
	if (i % 4 != 0)
		cout << endl;
	while (cin >> voice && (voice < 0 || voice >= Vtypes))
		cout << "Enter a value >=0 and <" << Vtypes << endl;
	while (cin.get() != '\n')
		continue;
}
void Singer::Show()const
{
	cout << "Category: Singer\n";
	Worker::Show();
	cout << "Vocal range: " << pv[voice] << endl;
}

void SingerWaiter::Show()const
{
	cout << "This is SingerWaiter use the Show()" << endl;
}

void SingerWaiter::Set()
{
	cout << "This is SingerWaiter use the Set()" << endl;
}