#include<iostream>

using namespace std;
class Screen {
public:
	Screen(int x) :i(x) {};
	int get() { return i; }

	void* operator new(size_t);
	void operator delete(void*, size_t);

private:
	Screen* next;
	static Screen* freeStore;
	static const int screenChunk;
private:
	int i;

};

Screen* Screen::freeStore = 0;
const int Screen::screenChunk = 24;

void* Screen::operator new(size_t size) {
	Screen* p;
	if (!freeStore) {
		size_t chunk = screenChunk * size;
		freeStore = p = reinterpret_cast<Screen*>(new char[chunk]);

		for (; p != &freeStore[screenChunk - 1]; ++p)
			p->next = p + 1;
		p->next = 0;
	}

	p = freeStore;
	freeStore = freeStore->next;

	return p;
}

void Screen::operator delete(void* p, size_t size) {
	(static_cast<Screen*>(p))->next = freeStore;
	freeStore = static_cast<Screen*>(p);
}


//------------------------------unionµÄÊ¹ÓÃ-------------------------------------------------
class Airplane {
private:
	struct AirplaneRep {
		unsigned long miles;
		char type;
	};
private:
	union {
		AirplaneRep rep;
		Airplane *next;
	};
public:
	unsigned long getMiles() { return rep.miles; }
	char getType() { return rep.type; }
	void set(unsigned long m, char t) {
		rep.miles = m;
		rep.type = t;
	}
public:
	static void* operator new(size_t size);
	static void operator delete(void* deadObject, size_t size);
private:
	static const int BLOCK_SIZE;
	static Airplane* headOfFreeList;
};

Airplane* Airplane::headOfFreeList;
const int Airplane::BLOCK_SIZE = 512;

void* Airplane::operator new(size_t size)
{
	if (size != sizeof(Airplane))
		return ::operator new(size);

	Airplane* p = headOfFreeList;
	if (p)
		headOfFreeList = p->next;
	else {
		Airplane *newBlock = static_cast<Airplane*>(::operator new(BLOCK_SIZE * sizeof(Airplane)));

		for (int i = 1; i < BLOCK_SIZE; ++i)
			newBlock[i].next = &newBlock[i + 1];
		newBlock[BLOCK_SIZE - 1].next = 0;
		p = newBlock;
		headOfFreeList = &newBlock[1];
	}

	return p;
}
void Airplane::operator delete(void* deadObject, size_t size)
{
	if (deadObject == 0)return;
	if (size != sizeof(Airplane)) {
		::operator delete(deadObject);
		return;
	}

	Airplane* carcass = static_cast<Airplane*>(deadObject);

	carcass->next = headOfFreeList;
	headOfFreeList = carcass;
}
//----------------------------------------------------------------------------


int main()
{
	//cout << sizeof(Screen) << endl;
	//size_t const N = 100;
	//Screen* p[N];

	//for (int i = 0; i < N; ++i)
	//	p[i] = new Screen(i);
	//
	//for (int i = 0; i < 10; ++i)
	//	cout << p[i] << endl;

	//for (int i = 0; i < N; ++i)
	//	delete p[i];
	


	return 0;
}