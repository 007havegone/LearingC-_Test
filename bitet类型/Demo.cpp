#include <iostream>
#include <bitset>
using namespace std;

int main()
{
	//use the unsigned to init the bitset
	bitset<13> bitvec1(0xbeff);
	bitset<20> bitvec2(0xbeff);
	bitset<128> bitvec3(~0ULL);
	//use the char[] to init the bitset
	bitset<32> bitvec4("1100");
	string str("1000111101");
	//use the string to init the bitset
	bitset<15> bitvec5(str, 5, 4);
	
	//operator for the bitset
	bitvec1.all();// all 1 return 1
	bitvec1.any();// exit a 1 return 1
	bitvec1.none(); // all 0 return 1
	bitvec1.count(); // return digit num of 1
	bitvec1.size();// return digit num
	bitvec1.test(4);// digit 4 is 1 return 1
	bitvec1.set(5);// set digit 5 to 1
	bitvec1.set(); //set all digit to 1
	bitvec1.reset(5);// reset the digit 5
	bitvec1.reset();//reset all digit
	bitvec1.flip();//reverse all digit
	bitvec1.flip(4);//revese digit 4
	cout << bitvec1[5];//return true of false
	bitvec1.to_string();//return a string 
	bitvec1.to_ulong();// return a unsigned long
	// IO the bitset
	cin >> bitvec1;
	cout << bitvec1;
	cout << bitvec1 << endl;
	cout << bitvec2 << endl;
	cout << bitvec3 << endl;
	cout << bitvec4 << endl;
}