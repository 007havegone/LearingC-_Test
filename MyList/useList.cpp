#include "MyList.h"
#include <iostream>
#include <random>
#include <ctime>
using namespace std;
void showMenu()
{
	cout << "ѡ���ܣ������Ӧ�����֣�[����q�˳�]" << endl;
	cout << "1����Ԫ��		2ɾ��Ԫ��" << endl;
	cout << "3��ȡԪ��		4������Ա�" << endl;
	cout << "5���Ƿ��		6���Ƿ�����" << endl;
	cout << "7��ʾ��		8��ӡ���Ա�" << endl;
	cout << "����ѡ�_____\b\b\b\b";
}
int main()
{
	int n;
	cout << "�������������Ա����󳤶�" << endl;
	while (cin >> n && n < 0)
		cout << "�������룬����Ӧ����0\n";
	ArrayList L(n);
	showMenu();
	char choose;
	while (cin >> choose && choose != '\q')
	{
		if (!strchr("12345678", choose))
		{
			cout << "���벻�Ϸ���������1-7�����" << endl;
			while (cin.get() != '\n')continue;//��ջ�����
		}
		else {
			int temp;
			int index;
			switch (choose)
			{
			case '1':L.Insert(rand() % 32656, L.getSize() + 1); break;//�嵽�����
			case '2':if(L.Delete(temp, 1))
						cout << "ɾ��Ԫ��Ϊ:" << temp << endl;
					 else cout << "ERROR" << endl; break;
			case '3':if(L.GetElemt(temp, 1))
						cout << "��һ��Ԫ��Ϊ:" << temp << endl;
					 else cout << "ERROR" << endl; break;
			case '4':L.Clear(); break;
			case '5':L.isEmpty() ? cout << "���Ա��ѿ�\n" : cout << "���Ա�ǿ�\n"; break;
			case '6':L.isFull() ? cout << "���Ա�����\n" : cout << "���Ա�δ��\n"; break;
			case '7':cout << L.getSize(); break;
			case '8':L.Show(); break;
			}
		}
		cout << endl;
		showMenu();
	}
	cout << "����Զϲ�����ٻ�.jpg" << endl;
	return 0;
}
