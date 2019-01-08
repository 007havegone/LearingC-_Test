#include <iostream>
#include <string>
using namespace std;

template<typename T> T fobj(T, T) {
	cout << fobj << endl;
}
template<typename T> T fref(const T&, const T&) {
	cout <<
}
string s1("a value");
const string s2("another value");



int main()
{
	fobj(s1, s2);

}