#include <iostream>
#include <queue>
using namespace std;

const int MAXSIZE = 100;
int m,n;//m个点顶点，n条边
int mp[MAXSIZE][MAXSIZE];
bool vis[MAXSIZE];
void BFS(int i)
{
	queue<int> q;
	q.push(i);
	while (!q.empty())
	{
		int temp = q.front(); q.pop();
		cout << temp << " ";
		vis[temp] = 1;
		for (int i = 1; i <= m; i++)
		{
			if (!vis[i] && mp[temp][i])
				q.push(i);
		}
	}
}
int main()
{
	int b, e;
	cin >> m >> n;
	memset(mp, 0, sizeof(mp));
	memset(vis, 0, sizeof(vis));
	while (n--)
	{
		cin >> b >> e;
		mp[b][e] = 1;
	}
	for (int i = 1; i <= m; i++)
	{
		if (!vis[i])
			BFS(i);
	}
}