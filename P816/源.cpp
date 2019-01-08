#include <iostream>
using namespace std;

class BS
{
	int q;
	double w;
public:
	BS() :q(0), w(0) {}
	BS(int k) :q(k), w(100) {}
	BS(double x) :q(-1), w(x) {}
	BS(int k, double x) :q(k), w(x) {}
	void show()const
	{
		cout << q << ", " << w << "\n";
	}
};
class DR :public BS
{
	short j;
public:
	using BS::BS;//将所有特征值不重复的导入
	DR() :j(-100) {}
	DR(double x) :BS(2 * x), j(int(x)) {}
	DR(int i) :j(-2), BS(i, 0.5*i) {}
	void show()const
	{
		cout << j << ",";
		BS::show();
	}
};
int main()
{
	DR o1;
	DR o2(18.81);//调用DR(double)
	DR o3(10, 1.7);//调用 BR(int,double)
	o1.show();
	o2.show();
	o3.show();
}
