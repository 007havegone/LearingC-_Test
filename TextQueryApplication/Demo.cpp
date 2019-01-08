#include "TextQuery.h"
#include "QueryResult.h"
#include <iostream>
#include <string>
#include <fstream>
using namespace std;


void SearchWord(TextQuery &qur)
{	
	string search;
	cout << "输入要查询的单词:\t\t输入q可以退出" << endl;
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
	cout << "成功输入文件" << endl;
	TextQuery qur(ifs);
	while (1)
	{
		string choose;
		cout << "1、Search a word \t\t"
			<< "2、Print the count of the Text(expect the Punctuation!)"
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
	cout << "输入要查询文件的绝对路径:" << endl;
	cin >> path;
	ifs.open(path, ifstream::in);
	while (!ifs.is_open())
	{
		cout << "文件未找到，重新输入文件路径" << endl;
		cin >> path;
		ifs.open(path, ifstream::in);
	}
	runQueries(ifs);
}