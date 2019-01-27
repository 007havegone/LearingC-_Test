#include <iostream>
#include <string>
using namespace std;

class Token {
public:
	Token() :tok(INT), ival(0) {}
	Token(const Token&t) :tok(t.tok) { copyUion(t); }
	Token& operator=(const Token&);
	//如果union含有一个string，则必须销毁他
	~Token() { if (tok == STR)sval.~string(); }

	//赋值
	Token& operator=(const std::string&);
	Token& operator=(char);
	Token& operator=(int);
	Token& operator=(double);
private:
	enum {INT,CHAR,DBL,STR}tok;//判别式
	union {//匿名union
		char cval;
		int ival;
		double dval;
		std::string sval;
	};//每个Token对象含有一个该未命名union类型的未命名成员
	//检查判别式,然后酌情拷贝union成员
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
