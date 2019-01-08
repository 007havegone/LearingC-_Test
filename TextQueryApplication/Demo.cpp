#include "TextQuery.h"
#include "QueryResult.h"
#include <iostream>
#include <string>
#include <fstream>
using namespace std;


void SearchWord(TextQuery &qur)
{	
	string search;
	cout << "����Ҫ��ѯ�ĵ���:\t\t����q�����˳�" << endl;
	while (cin >> search && search != "q")
	{
		QueryResult t = qur.find_word(search);
		t.Print();
	}
}
void CountinText(TextQuery &qur)
{
	cout << "The word count of text is" << endl;
	cout << qur.getWordCntInText() << endl;
}
void runQueries(ifstream &ifs)
{
	cout << "�ɹ������ļ�" << endl;
	TextQuery qur(ifs);
	while (1)
	{
		string choose;
		cout << "1��Search a word \t\t"
			<< "2��Print the count of the Text(expect the Punctuation!)"
			<< " Enter quit to quit!" << endl;
		cout << "Input your choose:";
		cin >> choose;
		if (choose == "quit")
			break;
		while (choose.length() > 1 || (choose != "1"&&choose != "2"))
		{
			cin.get();
			cin >> choose;
		}
		int chint = stoi(choose);
		switch (chint)
		{
		case 1:
			SearchWord(qur); break;
		case 2:
			CountinText(qur); break;
		default:
			return;
		}

	}
}
int main()
{
	string path;
	ifstream ifs;
	cout << "����Ҫ��ѯ�ļ��ľ���·��:" << endl;
	cin >> path;
	ifs.open(path, ifstream::in);
	while (!ifs.is_open())
	{
		cout << "�ļ�δ�ҵ������������ļ�·��" << endl;
		cin >> path;
		ifs.open(path, ifstream::in);
	}
	runQueries(ifs);
}