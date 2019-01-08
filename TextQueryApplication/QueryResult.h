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
	//ptΪ�ı����ݲ�����pLnumSetΪ���������м���
	QueryResult(pvec_str pt,pmap_strAndset pLnumset,const std::string & word)
		:ptext(pt),word_linenum(pLnumset),m_word(word) {}
	~QueryResult()=default;
	void Print();
private:
	pvec_str ptext;//�ı�����ָ��
	pmap_strAndset word_linenum;//����������������ָ��
	std::string m_word;//���ҵĵ���
};
void QueryResult::Print()
{
	auto linenum_ite = word_linenum->find(m_word);//��ȡ��һ��Ԫ�صĵ�����
	if (linenum_ite == word_linenum->end())//δ�ҵ�
		std::cout << "���ļ�û���ҵ��õ���" << std::endl;
	else
	{
		std::set<int> *pset = &linenum_ite->second;
		auto beg = pset->begin();//��ȡ���ϵĵ�һ��������
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

