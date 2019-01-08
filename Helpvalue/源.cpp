#include <iostream>
#include <string>
#include <queue>
using namespace std;

const int N = 100;//�������
const int INF = 0x3f3f3f3f;//�����
void Dijkstra(int st);
int link[N][N];
int dis[N];
int flag[N];
int n, m;//��������ϵ��
int ask;
struct Node
{
	int index, step;//iΪ���㣬stepΪĳ����ĳ�������Ѷ�
	Node(int mi, int mstep)//���ù��캯��,�����������
	{
		index = mi;
		step = mstep;
	}
	bool operator<(const Node& a)const {
		return step > a.step;//����
	}
};
int main()
{
	int a, b, v;
	cout << "����ѧ����:";
	cin >> n;
	cout << "�����ϵ��:";
	cin >> m;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
			link[i][j] = INF;//��ʼ��������û��ϵ
	}
	cout << "��������a,b����Ѱ��b��Ȩֵ" << endl;
	while (m--)
	{
		cin >> a >> b >> v;
		link[a][b] = v;
	}
	cout << "������ҵ�����" << endl;
	cin >> ask;
	Dijkstra(ask);
	for (int i = 1; i <= n; i++)
		if (dis[i] == INF)
			cout << ask << "�޷�Ѱ�� " << i << "�İ���";
		else
			cout << ask << "Ѱ��" << i << "�������Ѷ�Ϊ:" << dis[i] << endl;
	getchar();
	return 0;
}
void Dijkstra(int st)
{
	priority_queue<Node> pq;
	pq.push(Node(st, 0));
	memset(flag, 0, sizeof(flag));
	for (int i = 1; i <= n; i++)//��ʼ����ÿ����ľ���Ϊ0
		dis[i] = INF;
	dis[st] = 0;
	while (!pq.empty())
	{
		Node temp = pq.top();//��ȡ��ǰȨֵ��С�ĵ�
		pq.pop();//����
		int t = temp.index;//��ȡѧ���±�
		if (flag[t])
			continue;//�Ѿ����ʹ�������
		flag[t] = 1;//����Ϊ�ѷ���
		for (int i = 1; i <= n; i++)//������֮��ϵ�Ľڵ����
		{
			if (!flag[i] && link[t][i] < INF) {
				if (dis[i] > dis[t] + link[t][i])
				{
					dis[i] = dis[t] + link[t][i];
					pq.push(Node(i, dis[i]));//ѹ����º����̾���
				}
			}
		}
	}
}
