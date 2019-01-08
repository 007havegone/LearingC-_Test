#include <iostream>
#include "tv.h"

int main()
{
	using std::cout;
	Tv s42;
	s42.settings();
	s42.onoff();
	s42.chanup();
	s42.settings();
	s42.chanup();
	s42.settings();

	Remote grey;
	grey.set_chan(s42, 10);
	grey.volup(s42);
	grey.volup(s42);
	s42.settings();

	Tv s58(Tv::ON);
	s58.set_mode();
	grey.set_chan(s58, 28);
	s58.settings();
}