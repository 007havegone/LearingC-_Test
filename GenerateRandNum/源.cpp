#include <iostream>
#include <random>//c++ use the rand use
#include <stdlib.h>//for use rand() and srand()
#include <time.h>//for use the time()
#include <vector>
using namespace std;

vector<unsigned> bad_randVec()
{
	default_random_engine e;
	uniform_int_distribution<unsigned> u(0, 9);
	vector<unsigned> ret;
	for (size_t i = 0; i < 100; i++)
		ret.push_back(u(e));
	return ret;
}
vector<unsigned> good_randVec()
{
	//keep the engine static,then they can generate different nun
	//so define to static type
	static default_random_engine e;
	static uniform_int_distribution<unsigned> u;
	vector<unsigned> ret;
	for (size_t i = 0; i < 100; i++)
		ret.push_back(u(e));
	return ret;
}
int main()
{
	//traditional get a rand by c_function rand
	srand((unsigned)time(0));//return time in second
	cout << rand() << endl;
	cout << "RAND_MAX = " << RAND_MAX << endl;
	//c++ 随机数引擎
	default_random_engine e;//generate the unsigned num use default seed
	for (size_t i = 0; i < 10; ++i)
		cout << e() << " "; 
	cout << endl;
	//generate engine by seed,the same seed to generate same num
	default_random_engine e1(10);//use 10 as seed
	e1.seed(6);//reset the seed as 6
	cout << " e1(6) min: "<<e.min() << endl;
	cout << " e1(6) max: " << e.max() << endl;

	//此引擎推进15步
	e1.discard(static_cast<unsigned long long>(15));

	//分布类型引擎
	//生成[0,99]的均匀分布随机数
	uniform_int_distribution<unsigned> u(0, 99);
	for (size_t i = 0; i < 10; i++)
		cout << u(e) << " ";//use the default engine to a rand source
	cout << endl;
	//一般说随机数发生器，指分布对象和引擎对象的组合
	
	// use the bad_randVec()
	vector<unsigned> bad1 = bad_randVec();
	vector<unsigned> bad2 = bad_randVec();
	cout << ((bad1 == bad2) ? "equal" : "not equal") << endl;
	// use the good_randVec()
	vector<unsigned> good1 = good_randVec();
	vector<unsigned> good2 = good_randVec();
	cout << ((good1 == good2) ? "equal" : "not equal") << endl;

	//get the rand real num between 0 to 1
	uniform_real_distribution<double> reale(0, 1);
	for (size_t i = 0; i < 10; i++)
		cout << reale(e) << " ";
	cout << endl;

	//分布模板都有一个默认模板实参，生成浮点数默认double，生成整形默认int
	uniform_int_distribution<> defint(0,10);//默认为int型

	//同时新标准库定义了20分布类型，包括非均匀分布

}