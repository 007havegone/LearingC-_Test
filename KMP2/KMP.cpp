#include <iostream>
#include <cstring>
using namespace std;

int nextVal[100];
void getNext(char *str)
{
	int len = strlen(str);
	int i = 0, j = -1;//设next[0]=-1
	nextVal[0] = -1;
	while (i < len)
	{
		if (j == -1 || str[i] == str[j])
		{
			i++;
			j++;
			if (str[i] != str[j])
				nextVal[i] = j;
			else
				nextVal[i] = nextVal[j];
		}
		else
			j = nextVal[j];
	}
}
int KMP(char *str, char *find,int pos)//下表1-n
{
	int i = pos-1, j = 0;
	int len1 = strlen(str);
	int len2 = strlen(find);
	while (i < len1&&j < len2)
	{
		if (j == -1 || str[i] == find[j])
		{
			i++;
			j++;
		}
		else
			j = nextVal[j];
	}
	if (j == len2)
		return i - len2 + 1;//下标0开始，多加1
	return 0;
}
int main()
{
	char s[100];
	char t[20];
	int pos;
	cin >> s;
	cin >> t;
	cin >> pos;
	int len = strlen(t);
	getNext(t);
	for (int i = 0; i < len; i++)
		cout << nextVal[i] << " ";
	cout << endl;
	cout << KMP(s, t, pos) << endl;
}