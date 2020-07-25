#include<iostream>
#include<iterator>
#include<vector>
#include<algorithm>
#include<map>
#include<unordered_map>
#include<string>
#include<cassert>
#include <cstring>
#include <cstdio>
using namespace std;

#define OFFSET(s,m) size_t(&((s*)0)->m)

union TEST {
	short i;
	char c[sizeof(short)];
};
int main(int argc, char *argv[]) {

	TEST test;
	test.i = 0x0102;
	if (test.c[0] == 0x01 && test.c[1] == 0x02)
		cout << "big endian" << endl;
	else if (test.c[0] == 0x02 && test.c[1] == 0x01)
		cout << "small endian." << endl;
	else
		cout << "unkown.." << endl;
	return 0;
}