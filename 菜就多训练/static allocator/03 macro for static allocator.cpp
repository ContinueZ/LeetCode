#include<iostream>
#include<string>

using std::string;
class allocator {
private:
	struct obj {
		struct obj* next;
	};
public:
	void* allocate(size_t size);
	void deallocate(void*, size_t);
private:
	obj* freeStore = nullptr;
	const int CHUNK = 5;

};


//DECLARE_POOL_ALLOC-- used in class definition
#define DECLARE_POOL_ALLOC()\
public:\
	static void* operator new(size_t size){return myAlloc.allocate(size);}\
	static void operator delete(void* pDead, size_t size){return myAlloc.deallocate(pDead, size);}\
protected:\
	static allocator myAlloc;

//IMPLEMENT_POOL_ALLOC-- used in class definition
#define IMPLEMENT_POOL_ALLOC(class_name)\
allocator class_name::myAlloc;
	
class Foo {
	DECLARE_POOL_ALLOC()
public:
	long L;
	string str;
public:
	Foo(long l) :L(l) {}
};
IMPLEMENT_POOL_ALLOC(Foo)