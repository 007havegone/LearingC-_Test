// fowlup.cpp  -- unique_ptr not a good choice
#include <iostream>
#include <string>
#include <memory>

int main()
{
	using namespace std;
	unique_ptr<string> films[5] =
	{
		unique_ptr<string>(new string("Fowl Balls")),
		unique_ptr<string>(new string("Duck Walks")),
		unique_ptr<string>(new string("Chicken Runs")),
		unique_ptr<string>(new string("Turkey Errors")),
		unique_ptr<string>(new string("Goose Eggs"))
	};
	unique_ptr<string> pwin;
	pwin = move(films[2]);   // films[2], pwin both point to "Chicken Runs"
	films[2] = unique_ptr<string>(new string("Hello world"));
	shared_ptr<double[]> aa = shared_ptr<double[]>(new double[5]);
	unique_ptr<double[]> bb = unique_ptr<double[]>(new double[5]);
	//auto_ptr<double[]> cc = auto_ptr<double[]>(new double[5]);
	cout << "The nominees for best avian baseball film are\n";
	for (int i = 0; i < 5; i++)
		cout << *films[i] << endl;
	cout << "The winner is " << *pwin << "!\n";
	// cin.get();
	return 0;
}
