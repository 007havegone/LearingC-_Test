#include <iostream>
#include <algorithm>
#include <stack>
using namespace std;

const int MAXSIZE = 20;
int mp[MAXSIZE][MAXSIZE];
bool vis[MAXSIZE];
int m, n;//m个定点,n条边
void DFS(int n)
{
	cout << n << " ";
	vis[n] = 1;
	for (int i = 1; i <= m; i++)
	{
		if (!vis[i] && mp[n][i])
		{
			DFS(i);
		}
	}
}
void ReDFS(int n)
{
	stack<int> sta;//记录当前工作栈
	sta.push(n);
	while (!sta.empty())
	{
		int t = sta.top();
		sta.pop();
		if (!vis[t])
		{
			cout << t << " ";
			vis[t] = 1;
			for (int i = m; i >= 1; i--)//栈先入后出，想要按小到大可以从大到小压入
			{
				if (!vis[i] && mp[t][i])
					sta.push(i);
			}
		}
	}
}
int main()
{
	cin >> m >> n;
	memset(mp, 0, sizeof(mp));//初始化为0
	int b, e;
	while (n--)
	{
		cin >> b >> e;
		mp[b][e] = 1;
	}
	memset(vis, 0, MAXSIZE);
	for (int i = 1; i <= m; i++)
	{
		if (!vis[i])
			DFS(i);
	}
	cout << endl;
	memset(vis, 0, sizeof(vis));
	for (int i = 1; i <= m; i++)
	{
		if(!vis[i])
			ReDFS(i);
	}
}