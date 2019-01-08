#include <iostream>
#include <queue>
using namespace std;

const int MAXSIZE = 100;
const int INF = 0x3f;
int mp[MAXSIZE][MAXSIZE];
int n, m;
struct Edge
{
	int index;//下标
	int lowcost;//花费
	int vertex;//连接结点
	/*不可以，应为类型是Edge指针，不是Edge，需用定义一个比较器*/
	/*friend bool operator<(const Edge& e1, const Edge& e2)
	{
		return e1.lowcost > e2.lowcost;
	}*/
}VertexEdge[MAXSIZE];//每个结点的最小边信息
class Cmp
{
public:
	bool operator()(const Edge* e1,const Edge* e2)//重载为升序
	{
		return e1->lowcost > e2->lowcost;
	}
};
void MinSpanTree_Prim(int sta)//初始点
{
	/*priority_queue < Edge*, vector<Edge*>,Cmp> q;*/
	priority_queue<Edge*> q;
	for (int i = 1; i <= n; i++)
	{
		if (i != sta)
		{
			VertexEdge[i] = { i,mp[sta][i],sta };
			q.push(&VertexEdge[i]);//压入
		}
	}
	VertexEdge[sta] = { sta,0,sta };//初始化sta已加入
	cout << sta << " ";
	while (!q.empty())
	{
		Edge *t = q.top();//取出最小的点
		q.pop();
		//cout << t->vertex << " " << t->index << " " << t->lowcost << endl;
		cout << t->index << " ";
		t->lowcost = 0;//加入
		int id = t->index;
		for (int i = 1; i <= n; i++)
		{/*加入点，更新还未加入结点的最小值*/
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