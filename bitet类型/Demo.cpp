#include <iostream>
#include <bitset>
using namespace std;

int main()
{
	bitset<13> bitvec1(0xbeff);
	bitset<20> bitvec2(0xbeff);
	bitset<128> bitvec3(~0ULL);
	bitset<32> bitvec4("1100");
	cout << bitvec1 << endl;
	cout << bitvec2 << endl;
	cout << bitvec3 << endl;
	cout << bitvec4 << endl;
}