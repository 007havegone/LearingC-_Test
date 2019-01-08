#include "Stack.h"
#include <iostream>
#include <string>
using std::cout;
using std::endl;
using std::string;

int main()
{
	Stack<int> st;
	for (int i = 0; i <= 5; i++)
		st.push(i);
	for (int i = 0; i < 5; i++)
	{
		int t;
		st.pop(t);
		cout << t <<" ";
	}
	cout << endl;
	Stack<string> ss;
	ss.push("Jom");
	ss.push("Tom");
	ss.push("Lily");
	cout << "This stack size is : " << ss.size() << endl;
	for (int i = 0; i < 3; i++)
	{
		string s;
		ss.pop(s);
		cout << s << " ";
	}
	cout << endl;
	return 0;
}