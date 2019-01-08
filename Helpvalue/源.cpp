#include <iostream>
#include <string>
#include <queue>
using namespace std;

const int N = 100;//最大人数
const int INF = 0x3f3f3f3f;//无穷大
void Dijkstra(int st);
int link[N][N];
int dis[N];
int flag[N];
int n, m;//人数，关系数
int ask;
struct Node
{
	int index, step;//i为顶点，step为某人向某人求助难度
	Node(int mi, int mstep)//设置构造函数,方便后面生成
	{
		index = mi;
		step = mstep;
	}
	bool operator<(const Node& a)const {
		return step > a.step;//升序
	}
};
int main()
{
	int a, b, v;
	cout << "输入学生数:";
	cin >> n;
	cout << "输入关系数:";
	cin >> m;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
			link[i][j] = INF;//初始化两两间没联系
	}
	cout << "输入两者a,b及其寻求b的权值" << endl;
	while (m--)
	{
		cin >> a >> b >> v;
		link[a][b] = v;
	}
	cout << "输入查找的人物" << endl;
	cin >> ask;
	Dijkstra(ask);
	for (int i = 1; i <= n; i++)
		if (dis[i] == INF)
			cout << ask << "无法寻求到 " << i << "的帮助";
		else
			cout << ask << "寻求" << i << "帮助的难度为:" << dis[i] << endl;
	getchar();
	return 0;
}
void Dijkstra(int st)
{
	priority_queue<Node> pq;
	pq.push(Node(st, 0));
	memset(flag, 0, sizeof(flag));
	for (int i = 1; i <= n; i++)//初始化到每个点的距离为0
		dis[i] = INF;
	dis[st] = 0;
	while (!pq.empty())
	{
		Node temp = pq.top();//获取当前权值最小的点
		pq.pop();//弹出
		int t = temp.index;//获取学生下标
		if (flag[t])
			continue;//已经访问过，跳过
		flag[t] = 1;//设置为已访问
		for (int i = 1; i <= n; i++)//更新与之联系的节点距离
		{
			if (!flag[i] && link[t][i] < INF) {
				if (dis[i] > dis[t] + link[t][i])
				{
					dis[i] = dis[t] + link[t][i];
					pq.push(Node(i, dis[i]));//压入更新后的最短距离
				}
			}
		}
	}
}
