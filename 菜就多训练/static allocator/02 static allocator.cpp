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

void* allocator::allocate(size_t size)
{
	obj* p;

	if (!freeStore) {
		size_t chunk = CHUNK * size;
		freeStore = p = (obj*)malloc(chunk);

		for (int i = 0; i < (CHUNK - 1); ++i) {
			p->next = (obj*)((char*)p + size);
			p = p->next;
		}
		p->next = nullptr;
	}

	p = freeStore;
	freeStore = freeStore->next;
	return p;
}

void allocator::deallocate(void* p, size_t size)
{
	((obj*)p)->next = freeStore;
	freeStore = (obj*)p;
}

class Foo {
public:
	long L;
	string str;
	static allocator myAlloc;
public:
	Foo(long l):L(l){}
	static void* operator new(size_t size)
	{
		return myAlloc.allocate(size);
	}
	static void operator delete(void* pDead, size_t size)
	{
		return myAlloc.deallocate(pDead, size);
	}
};

allocator Foo::myAlloc;