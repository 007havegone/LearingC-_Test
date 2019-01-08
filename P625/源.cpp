#include <iostream>
#include <cstring>
using namespace std;

template<typename T> int compare(const T&t1, const T&t2)
{
	if (t1 < t2)
		return -1;
	if (t1 > t2)
		return 1;
	return 0;
}
//specific
template<> int compare(const char* const& t1, const char* const& t2)
{
	return strcmp(t1, t2);
}
template<size_t N, size_t M>
int compare(const char(&a)[N], const char(&b)[M])
{
	int i = 0;
	int j = 0;
	while (i < N&&j < M)
	{
		if (a[i] == b[i])
		{
			i++;
			j++;
		}
		else if (a[i] < b[i])
			return -1;
		else
			return 1;
	}
	if (i < N)
		return -1;
	else if (j < M)
		return 1;
	return 0;
}

int main()
{

	const char *p1 = "hi", *p2 = "zhi";
	cout << compare(p1, p2) << endl;
	cout << compare("hi", "hi1");
}