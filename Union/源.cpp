#include <iostream>
#include <string>
using namespace std;

class Token {
public:
	Token() :tok(INT), ival(0) {}
	Token(const Token&t) :tok(t.tok) { copyUion(t); }
	Token& operator=(const Token&);
	//���union����һ��string�������������
	~Token() { if (tok == STR)sval.~string(); }

	//��ֵ
	Token& operator=(const std::string&);
	Token& operator=(char);
	Token& operator=(int);
	Token& operator=(double);
private:
	enum {INT,CHAR,DBL,STR}tok;//�б�ʽ
	union {//����union
		char cval;
		int ival;
		double dval;
		std::string sval;
	};//ÿ��Token������һ����δ����union���͵�δ������Ա
	//����б�ʽ,Ȼ�����鿽��union��Ա
	void copyUion(const Token&);
};
int main() {
	union {
		char cval;
		int ival;
	};
	ival = 16;;
	cout << ival;
}

void Token::copyUion(const Token &t)
{
	switch (t.tok){
		case Token::INT:ival = t.ival; break;
		case Token::CHAR:cval = t.cval; break;
		case Token::DBL:dval = t.dval; break;
		case Token::STR:new(&sval)string(t.sval); break;
	}
}
Token& Token::operator=(int i)
{
	if(tok==STR)sval.~string;
	ival = i;
	tok = INT;
	return *this;
}
Token& Token::operator=(double d)
{
	if (tok == STR)sval.~string;
	ival = d;
	tok = DBL;
	return *this;
}
Token& Token::operator=(char c)
{
	if (tok == STR)sval.~string;
	ival = c;
	tok = CHAR;
	return *this;
}
Token& Token::operator=(const string&s)
{
	if (tok == STR)
		sval = s;
	else
		new(&sval)string(s);
	tok = STR;
	return *this;
}
Token& Token::operator=(const Token&t)
{
	if (tok == STR && t.tok != STR)sval.~string();
	if (tok == STR && t.tok == STR)
		sval = t.sval;
	else
		copyUion(t);
	tok = t.tok;
	return *this;
}
