#include "LinkedList.h"
using namespace std;

void Init(LinkList &L);
int main()
{
	LinkList L;
	Init(L);//��������
	reverseList(L,1);//��ת���������ǩ1
	cout << "��ת��:" << L << endl;

}
void Init(LinkList &L)
{
	int n;
	cout << "����Ԫ�ظ���:";
	cin >> n;
	CreatLkList(L, n);
	cout << endl;
}
