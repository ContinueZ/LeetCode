#include <iostream>

using std::cout;
using std::endl;

class Bclass
{
public:
	void funTest() {
		fun();
	}
private:
	virtual void fun() { cout << "Bclass fun is here!" << endl; }
	void fun2() { cout << "Bclass fun2 is here!" << endl; }
	//friend int main();
};

class Dclass : public Bclass
{
public:
	virtual void fun() { cout << "Dclass fun is here!" << endl; }
	void fun2() { cout << "Dclass fun2 is here!" << endl; }
};


int main()
{
	Bclass *pObject = new Dclass();
	pObject->funTest();
	//pObject->fun2();

	return 0;
}