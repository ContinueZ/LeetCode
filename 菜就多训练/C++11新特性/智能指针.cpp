#include<iostream>

using namespace std;

int main()
{
	unique_ptr<string> p1(new string("hello"));
	unique_ptr<string> p2;
	//p2 = p1;
	p2 = move(p1);
	cout << p1 << endl;
	cout << p2 << endl;

	return 0;
}