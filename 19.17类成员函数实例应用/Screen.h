#include <iostream>
#include <tuple>
/*���������ͬ���Զ���һ����̬����������Ȼ��ͨ��һ��������������*/
typedef std::tuple<int, int, int>  Pos;
class Screen {
public:
	//����һ���ƶ�������ָ��
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
	//���ú���ͬʱ����Screen&
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
//����tuple����
template<class Tuple, std::size_t N>//ͨ��ģ��
struct TuplePrinter {
	static void print(const Tuple& t)
	{
		TuplePrinter<Tuple, N - 1>::print(t);//��ӡǰN-1��
		//get���ܵ�i��Ҫ��Ϊ�����͵�ģ�����,�����޷�����
		std::cout << ", " << std::get<N - 1>(t);//��ӡ����N��
	}
};

template<class Tuple>//������ģ�壬����
struct TuplePrinter<Tuple, 1> {
	static void print(const Tuple& t)
	{
		std::cout << std::get<0>(t);
	}
};
//������Ϊʲô
template<typename Tuple, size_t N>
void tuple_print(const Tuple& t, std::ostream& os)
{
	if (N != 1)
		tuple_print<Tuple, N - 1>(t, os);
	os << std::get<N - 1>(t);
}
//�ɱ����ģ�壬����һ��tuple
template<class... Args>
void PrintTuple(const std::tuple<Args...>& t)
{
	std::cout << "(";
	TuplePrinter<decltype(t), sizeof...(Args)>::print(t);
	//tuple_print<decltype(t), sizeof...(Args)>(t, cout);
	std::cout << ")\n";
}

