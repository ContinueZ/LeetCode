#include<iostream>

using namespace std;

class Foo {
public:
	int id;
	long data;
	string str;
public:
	Foo() :id() { cout << "default ctor.this=" << this << " id=" << id << endl; }
	Foo(int i) :id(i) { cout << "ctor.this=" << this << " id=" << id << endl; }

	//virtual
	~Foo() { cout << "dtor.this=" << this << " id=" << id << endl; }

	static void* operator new(size_t size);
	static void operator delete(void* pdead, size_t size);
	static void* operator new[](size_t size);
	static void operator delete[](void*pdead, size_t size);
};

void* Foo::operator new(size_t size) {
	Foo* p = (Foo*)malloc(size);
	cout << "operator new be called" << endl;
	return p;
}

void Foo::operator delete(void* pdead, size_t size) {
	cout << "operator delete be called" << endl;
	free(pdead);
}
void* Foo::operator new[](size_t size) {
	Foo* p = (Foo*)malloc(size);
	cout << "operator new[] be called" << endl;
	return p;
}
void Foo::operator delete[](void* pdead, size_t size) {
	cout << "operator delete[] be called" << endl;
	free(pdead);
}

int main()
{
	cout << "sizeof(Foo)" << sizeof(Foo) << endl;

	Foo* p = new Foo(7);
	delete p;

	cout << "----------------------" << endl;
	Foo* pArray = new Foo[5];
	delete[] pArray;

	return 0;
}