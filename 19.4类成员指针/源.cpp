#include <iostream>
#include <string>
using namespace std;

class Screen {
public:
	typedef std::string::size_type pos;
	Screen(const std::string &str,pos c=0,pos h=100,pos w=100):contents(str),
								cursor(c),height(h),width(w){}
	char get_cursor() { return contents[cursor]; }
	char get() const;
	char get(pos ht, pos wd)const {
		return contents[(ht+wd)/2];
	}
	static const string Screen::*Content() {
		return &Screen::contents;
	}
private:
	std::string contents;
	pos cursor;
	pos height, width;
};

//使用类型别名或typdef,和普通函数指针一样，也可以作为参数和返回类型
typedef char(Screen::*Brief)(Screen::pos, Screen::pos)const;
using Action = char(Screen::*)(Screen::pos, Screen::pos)const;
Screen& action(Screen&sc, Action = &Screen::get)
{
	return sc;
}
int main()
{
	//数据成员指针
	const string Screen::*pdata = Screen::Content();
	Screen s1("Hello");
	Screen s2("World");
	Screen *ps = &s2;
	cout << s1.*pdata << " " << ps->*pdata << endl;

	//成员函数指针
	auto pmf = &Screen::get_cursor;
	//定义指向Screen::get的成员函数指针
	char (Screen::*pmf2)(Screen::pos, Screen::pos)const;
	pmf2 = &Screen::get;//与普通函数不同，需要用取地址运算符
	
	char c1 = (s1.*pmf)();//不可省略*
	char c2 = (ps->*pmf2)(0, 6);
	cout << "c1 = " << c1 << " c2 = " << c2 << endl;
	
	//应用定义的别名
	Action get = &Screen::get;
	Brief get2 = &Screen::get;
	action(s1, get);
	action(s1, &Screen::get);
	action(s2);
	
}