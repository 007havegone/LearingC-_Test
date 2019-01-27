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

//ʹ�����ͱ�����typdef,����ͨ����ָ��һ����Ҳ������Ϊ�����ͷ�������
typedef char(Screen::*Brief)(Screen::pos, Screen::pos)const;
using Action = char(Screen::*)(Screen::pos, Screen::pos)const;
Screen& action(Screen&sc, Action = &Screen::get)
{
	return sc;
}
int main()
{
	//���ݳ�Աָ��
	const string Screen::*pdata = Screen::Content();
	Screen s1("Hello");
	Screen s2("World");
	Screen *ps = &s2;
	cout << s1.*pdata << " " << ps->*pdata << endl;

	//��Ա����ָ��
	auto pmf = &Screen::get_cursor;
	//����ָ��Screen::get�ĳ�Ա����ָ��
	char (Screen::*pmf2)(Screen::pos, Screen::pos)const;
	pmf2 = &Screen::get;//����ͨ������ͬ����Ҫ��ȡ��ַ�����
	
	char c1 = (s1.*pmf)();//����ʡ��*
	char c2 = (ps->*pmf2)(0, 6);
	cout << "c1 = " << c1 << " c2 = " << c2 << endl;
	
	//Ӧ�ö���ı���
	Action get = &Screen::get;
	Brief get2 = &Screen::get;
	action(s1, get);
	action(s1, &Screen::get);
	action(s2);
	
}