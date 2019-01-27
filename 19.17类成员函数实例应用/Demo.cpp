#include <iostream>
#include <string>
#include "Screen.h"
#include <tuple>
using namespace std;
//初始化函数表
Screen::Action Screen::Menu[] = {
	&Screen::home,
	&Screen::forward,
	&Screen::back,
	&Screen::up,
	&Screen::down,
	&Screen::left,
	&Screen::right,
};

int main() {
	Screen myscreen;
	myscreen.move(Screen::HOME);
	myscreen.move(Screen::FORWARD);
	myscreen.move(Screen::UP);
	Pos loc = myscreen.getPosition();
	size_t s = tuple_size<decltype(loc)>::value;
	PrintTuple(loc);
	
}