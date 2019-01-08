#include "pra2.h"
#include <iostream>
using namespace std;

int main()
{
	Gloam g = Gloam(10, "Hello World");
	Gloam h = Gloam(g);
	cout << (void*)g.getAd() << endl;
	cout << (void*)h.getAd() << endl;
}