#ifndef PRA2_H_
#define PRA2_H_
#include <iostream>
#include <cstring>
using std::cout;
using std::endl;
class Frabjous {
private:
	char fab[20];
public:
	Frabjous(const char* s = "c++")
	{
		std::strcpy(fab, s);
	}
	virtual void tell() { cout << fab ; }
	char* getAd() { return fab; }
};
class Gloam
{
private:
	int glib;
	Frabjous fb;
public:
	Gloam(int g = 0, const char*s = "C++");
	Gloam(int g, const Frabjous& f);
	void tell();
	char* getAd() { return fb.getAd(); }
};
Gloam::Gloam(int g, const char* s) :fb(s), glib(g){}
void Gloam::tell()
{
	fb.tell();
	cout << " " << glib << endl;;
}
#endif // !PRA2_H_
