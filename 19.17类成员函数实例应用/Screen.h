#include <iostream>
#include <tuple>
/*多个函数相同可以定义一个静态函数表，返回然后通过一个公共函数调用*/
typedef std::tuple<int, int, int>  Pos;
class Screen {
public:
	//定义一个移动函数的指针
	using Action = Screen & (Screen::*)();
	typedef int pos;
	Screen(pos x=0,pos y=0,pos z=0) {
		m_x = x;
		m_y = y;
		m_z = z;
	}
	Screen& home();
	Screen& forward();
	Screen& back();
	Screen& up();
	Screen& down();
	Screen& left();
	Screen& right();
	enum Directions { HOME, FORWARD, BACK, UP, DOWN, LEFT, RIGHT };
	Screen& move(Directions);
	Pos getPosition() {
		return std::make_tuple(m_x, m_y, m_z);
	}
	
private:
	static Action Menu[];
	pos m_x;
	pos m_y;
	pos m_z;
};

Screen& Screen::move(Screen::Directions cm)
{
	//调用函数同时返回Screen&
	return (this->*Menu[cm])();
}
Screen& Screen::home() {
	m_x = m_y = m_z = 0;
	return *this;
}
Screen& Screen::forward() {
	m_x += 10;
	return *this;
}
Screen& Screen::back() {
	m_x -= 10;
	return *this;
}
Screen& Screen::up() {
	m_z += 10;
	return *this;
}
Screen& Screen::down() {
	m_z -= 10;
	return *this;
}
Screen& Screen::left() {
	m_y -= 10;
	return *this;
}
Screen& Screen::right() {
	m_y += 10;
	return *this;
}
//遍历tuple类型
template<class Tuple, std::size_t N>//通用模板
struct TuplePrinter {
	static void print(const Tuple& t)
	{
		TuplePrinter<Tuple, N - 1>::print(t);//打印前N-1个
		//get接受的i需要作为非类型的模板参数,否则无法编译
		std::cout << ", " << std::get<N - 1>(t);//打印最后第N个
	}
};

template<class Tuple>//特例化模板，出口
struct TuplePrinter<Tuple, 1> {
	static void print(const Tuple& t)
	{
		std::cout << std::get<0>(t);
	}
};
//不可以为什么
template<typename Tuple, size_t N>
void tuple_print(const Tuple& t, std::ostream& os)
{
	if (N != 1)
		tuple_print<Tuple, N - 1>(t, os);
	os << std::get<N - 1>(t);
}
//可变参数模板，接受一个tuple
template<class... Args>
void PrintTuple(const std::tuple<Args...>& t)
{
	std::cout << "(";
	TuplePrinter<decltype(t), sizeof...(Args)>::print(t);
	//tuple_print<decltype(t), sizeof...(Args)>(t, cout);
	std::cout << ")\n";
}

