#include <iostream>
#include <iterator>
#include <vector>

int main()
{
	using namespace std;

	int casts[] = { 6,7,2,9,4,11,8,7,10,5 };
	vector<int> dice(10);

	copy(casts, casts+10, dice.begin());
	cout << "show the dice：" << endl;

	ostream_iterator<int, char> out_iter(cout, " ");//输入int，以char形式展示，cout输出，每个元素用“ ”隔开
	//copy vector to output
	copy(dice.begin(), dice.end(), out_iter);
	cout << endl;
	cout << "反向输出:" << endl;
	copy(dice.rbegin(), dice.rend(), out_iter);
	cout << endl;

	vector<int>::reverse_iterator ri;
	for (ri = dice.rbegin(); ri != dice.rend();++ri)
		cout << *ri << " ";
	cout << endl;

	return 0;
}