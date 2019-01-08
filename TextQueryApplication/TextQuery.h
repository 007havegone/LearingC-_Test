#ifndef  TEXTQUERY_H_
#define TEXTQUERY_H_
#include "QueryResult.h"
#include <vector>
#include <memory>
#include <fstream>
#include <string>
#include <sstream>
#include <algorithm>
#include <utility>
#include <set>
#include <map>
#include <cassert>
class TextQuery
{
	friend class QueryResult;
	using pvec_str = std::shared_ptr < std::vector < std::string >>;
	using pmap_strAndset = std::shared_ptr<std::map<std::string, std::set<int>>>;
public:
	TextQuery(std::ifstream &ifs);
	~TextQuery();
	void showSizeofSet();
	size_t getWordCntInText() { return wordCntInText; }
	QueryResult find_word(const std::string& word);

private:
	pvec_str text;//�����ı�
	pmap_strAndset word_to_linenum;//�����������м���ӳ��
	size_t wordCntInText=0;
};
void TextQuery::showSizeofSet()
{
	auto ps = word_to_linenum->begin();
	int i = 1;
	while (ps != word_to_linenum->end())
	{
		std::cout << "The " << i << "set "<< ps->first<<" size is " << ps->second.size() << std::endl;
		ps++;
	}
}
//�����ı�
TextQuery::TextQuery(std::ifstream &ifs)
	:text(std::make_shared<std::vector<std::string>>()), 
	word_to_linenum(std::make_shared<std::map<std::string,std::set<int>>>())
{
	std::string line;//һ��
	int line_num = 1;
	while (std::getline(ifs, line))
	{
		line = line.substr(0, line.find_last_of(" ,.")+1);
		text->push_back(line);//error
		std::istringstream iss(line);
		std::string word;
		//std::cout << iss.str() << std::endl;
		while (iss >> word)
		{
			size_t pos = std::string::npos;
			if ((pos=word.find_first_of(",.!?"))!=std::string::npos && pos == 0)
				word.erase(0);
			if ((pos=word.find_last_of(".,!?")) != std::string::npos && pos==word.length() - 1)
				word.erase(pos);
			wordCntInText++;//�������1
			std::pair<std::string, std::set<int>> p(word, { line_num});
			//resΪһ��pair<map::iterator<string,set>,bool>
			auto res = word_to_linenum->insert(p);
			if (!res.second)//�Ѿ����ڣ��������еļ������Ӹ�������
			{
				res.first->second.insert(line_num);
				/*the same with 
					std::map<std::string,std::set<int>>::iterator map_ite=res.first;
					std::set<int> st=map_ite->second;
					st.insert(line_num);
				*/
			}
		}
		line_num++;
	}
	//showSizeofSet();
}

QueryResult TextQuery::find_word(const std::string & word)
{
	return QueryResult(text, word_to_linenum, word);
}

TextQuery::~TextQuery()
{
}
#endif //  TEXTQUERY_H_

