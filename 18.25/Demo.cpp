#include <iostream>
using namespace std;
class Base1 {
public:
	virtual void print() {
		cout << "Base1 print()" << endl;
	}
	virtual ~Base1() {
		cout << "~Base1" << endl;
	}
};
class Base2 {
public:
	virtual void print() {
		cout << "Base2 print()" << endl;
	}
	virtual ~Base2() {
		cout << "~Base2" << endl;
	}
};
class D1 :public Base1 {
public:
	virtual void print() {
		cout << "D1 print()" << endl;
	}
	virtual ~D1() {
		cout << "~D1()" << endl;
	}
};
class D2 :public Base2 {
public:
	virtual void print() {
		cout << "D2 print()" << endl;
	}
	virtual ~D2() {
		cout << "~D2()" << endl;
	}
};
class MI :public D1, public D2 {
public:
	virtual void  print() {
		cout << "MI" << endl;
	}
	virtual ~MI() {
		cout << "MI" << endl;
	}
};

int main() {

}