#include <iostream>
#include <string>
#include <cstring>
using namespace std;

int getIndex(string str, string f,int pos)
{
	int i = pos-1;
	int j = 0;
	while (i < str.length()&&j < f.length())
	{
		if (str[i] == f[j])
		{
			i++;
			j++;
		}
		else
		{
			i = i - j + 1;//如果下标从1开始则为j=1,i=i-j+2
			j = 0;
		}
	}
	if (j == f.length())
		return i - j + 1;//如果下标1开始不用加1
	return 0;
}
int getCharIndex(char *str, char *f,int pos)
{
	int i = pos;
	int j = 1;
	int len1 = strlen(str)-1;
	int len2 = strlen(f)-1;
	cout << len1 << " " << len2 << endl;
	while (i <= len1 && j <= len2)
	{
		if (str[i] == f[j])
		{
			i++;
			j++;
		}
		else
		{
			i = i - j + 2;//匹配成功j-1个，并从下一个开始
			j = 1;
		}
	}
	if (j > len2)
		return i - len2;
	return 0;

}
int main()
{
	/*string s;
	string t;
	cin >> s;
	cin >> t;
	cout << getIndex(s, t, 7) << endl;*/

	char a[100];
	char b[5];
	int f;
	cin >> a + 1;
	cin >> b + 1;
	cin >> f;
	cout << getCharIndex(a, b, f) << endl;
}
