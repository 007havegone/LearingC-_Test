#include "LinkedList.h"
using namespace std;

void Init(LinkList &L);
int main()
{
	LinkList L;
	Init(L);//创建链表
	reverseList(L,1);//反转链表，传入标签1
	cout << "反转后:" << L << endl;

}
void Init(LinkList &L)
{
	int n;
	cout << "输入元素个数:";
	cin >> n;
	CreatLkList(L, n);
	cout << endl;
}
