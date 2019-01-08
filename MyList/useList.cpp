#include "MyList.h"
#include <iostream>
#include <random>
#include <ctime>
using namespace std;
void showMenu()
{
	cout << "选择功能，输出相应的数字：[输入q退出]" << endl;
	cout << "1插入元素		2删除元素" << endl;
	cout << "3获取元素		4清空线性表" << endl;
	cout << "5表是否空		6表是否已满" << endl;
	cout << "7显示表长		8打印线性表" << endl;
	cout << "输入选项：_____\b\b\b\b";
}
int main()
{
	int n;
	cout << "创建表，输入线性表的最大长度" << endl;
	while (cin >> n && n < 0)
		cout << "重新输入，长度应大于0\n";
	ArrayList L(n);
	showMenu();
	char choose;
	while (cin >> choose && choose != '\q')
	{
		if (!strchr("12345678", choose))
		{
			cout << "输入不合法，请输入1-7的序号" << endl;
			while (cin.get() != '\n')continue;//清空缓冲区
		}
		else {
			int temp;
			int index;
			switch (choose)
			{
			case '1':L.Insert(rand() % 32656, L.getSize() + 1); break;//插到最后面
			case '2':if(L.Delete(temp, 1))
						cout << "删除元素为:" << temp << endl;
					 else cout << "ERROR" << endl; break;
			case '3':if(L.GetElemt(temp, 1))
						cout << "第一个元素为:" << temp << endl;
					 else cout << "ERROR" << endl; break;
			case '4':L.Clear(); break;
			case '5':L.isEmpty() ? cout << "线性表已空\n" : cout << "线性表非空\n"; break;
			case '6':L.isFull() ? cout << "线性表已满\n" : cout << "线性表未满\n"; break;
			case '7':cout << L.getSize(); break;
			case '8':L.Show(); break;
			}
		}
		cout << endl;
		showMenu();
	}
	cout << "我永远喜欢加藤惠.jpg" << endl;
	return 0;
}
