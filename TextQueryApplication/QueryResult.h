#ifndef QUERYRESULT_H_
#define QUERYRESULT_H_
#include <string>
#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <memory>
class TextQuery;
class QueryResult
{
	using pvec_str=std::shared_ptr<std::vector<std::string>>;
	using pmap_strAndset = std::shared_ptr<std::map<std::string, std::set<int>>>;
public:
	//pt为文本内容参数，pLnumSet为单词所在行集合
	QueryResult(pvec_str pt,pmap_strAndset pLnumset,const std::string & word)
		:ptext(pt),word_linenum(pLnumset),m_word(word) {}
	~QueryResult()=default;
	void Print();
private:
	pvec_str ptext;//文本内容指针
	pmap_strAndset word_linenum;//单词所在行数集合指针
	std::string m_word;//查找的单词
};
void QueryResult::Print()
{
	auto linenum_ite = word_linenum->find(m_word);//获取第一个元素的迭代器
	if (linenum_ite == word_linenum->end())//未找到
		std::cout << "该文件没有找到该单词" << std::endl;
	else
	{
		std::set<int> *pset = &linenum_ite->second;
		auto beg = pset->begin();//获取集合的第一个迭代器
		std::cout << "*beg = " << *beg << std::endl;
		auto cnt = pset->size();
		std::cout << "There are " << cnt <<" "<< m_word << " exist in this Fiel Text." << std::endl;
		std::cout << "They can be listed as followed:" << std::endl;
		while (beg != pset->end())
		{
			std::cout << "# Line " << *beg << " : " << (*ptext)[size_t(*beg) - 1] << std::endl;
			beg++;
		}
	}
}
#endif // !QUERYRESULT_H_

