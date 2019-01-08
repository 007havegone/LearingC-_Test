#include <iostream>
#include <queue>
using namespace std;

const int MAXSIZE = 100;
const int INF = 0x3f;
int mp[MAXSIZE][MAXSIZE];
int n, m;
struct Edge
{
	int index;//�±�
	int lowcost;//����
	int vertex;//���ӽ��
	/*�����ԣ�ӦΪ������Edgeָ�룬����Edge�����ö���һ���Ƚ���*/
	/*friend bool operator<(const Edge& e1, const Edge& e2)
	{
		return e1.lowcost > e2.lowcost;
	}*/
}VertexEdge[MAXSIZE];//ÿ��������С����Ϣ
class Cmp
{
public:
	bool operator()(const Edge* e1,const Edge* e2)//����Ϊ����
	{
		return e1->lowcost > e2->lowcost;
	}
};
void MinSpanTree_Prim(int sta)//��ʼ��
{
	/*priority_queue < Edge*, vector<Edge*>,Cmp> q;*/
	priority_queue<Edge*> q;
	for (int i = 1; i <= n; i++)
	{
		if (i != sta)
		{
			VertexEdge[i] = { i,mp[sta][i],sta };
			q.push(&VertexEdge[i]);//ѹ��
		}
	}
	VertexEdge[sta] = { sta,0,sta };//��ʼ��sta�Ѽ���
	cout << sta << " ";
	while (!q.empty())
	{
		Edge *t = q.top();//ȡ����С�ĵ�
		q.pop();
		//cout << t->vertex << " " << t->index << " " << t->lowcost << endl;
		cout << t->index << " ";
		t->lowcost = 0;//����
		int id = t->index;
		for (int i = 1; i <= n; i++)
		{/*����㣬���»�δ���������Сֵ*/
			if (VertexEdge[i].lowcost && mp[id][i] < VertexEdge[i].lowcost)
			{
				VertexEdge[i].lowcost = mp[id][i];
				VertexEdge[i].vertex = id;
			}
		}
	}
}
int main()
{
	int be, ed, val;
	cin >> n >> m;
	memset(mp, INF, sizeof(mp));
	//cout << mp[0][0] << endl;
	while (m--)
	{
		cin >> be >> ed >> val;
		if (val < mp[be][ed]) {
			mp[be][ed] = val;
			mp[ed][be] = val;
		}
	}
	cout << endl;
	MinSpanTree_Prim(1);
}