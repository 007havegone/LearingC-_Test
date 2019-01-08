#include <iostream>
#include <cstring>
using namespace std;

int nextval[100];
void getNext(char *t, int *nex)
{
	int i = 1;
	int j = 0;//设置j为next[i]的上一个备份
	nex[1] = 0;//设置next[1]=0
	int len = strlen(t) - 1;
	while (i <= len)
	{
		if (j == 0 || t[i] == t[j])//如果next[i]==0或则t[i]==t[next[i]]
		{
			i++; j++;
			if (t[i] != t[j])
				nex[i] = j;//next[i+1]=next[i]+1
			else
				nex[i] = nex[j];//t[i]==t[j],可知当t[i]!=s[i],则t[j]!=s[i],则可以不用比较多余一步，直接让next[i]=next[next[i]]=next[k]
		}
		else
			j = nex[j];//next[i]=next[next[i]]=next[k]
	}
}
int KMP(char *str, char *f,int pos)
{
	int lens = strlen(str) - 1;
	int lenf = strlen(f) - 1;
	int i = pos, j = 1;
	while (i <= lens && j <= lenf)
	{
		if (j==0||str[i] == f[j])
		{
			i++;
			j++;
		}
		else
			j = nextval[j];
	}
	if (j > lenf)
		return i - lenf;
	else
		return 0;
}
int main()
{
	char s[100];
	char t[20];
	int front;
	cin >> s + 1;//下标从1开始
	cin >> t + 1;//下标从1开始
	cin >> front;
	int lent = strlen(t)-1;
	getNext(t, nextval);
	for (int i = 1; i <= lent; i++)
		cout << nextval[i] << " ";
	cout << endl;
	cout << KMP(s, t, front) << endl;

}