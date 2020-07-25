

//设计良好的new handler只有两个选择
//1.让更多memory可用
//2.调用abort（）或者exit（）

#include <iostream>
#include<cassert>
using namespace std;

void noMoreMemory() {
	cerr << "out of memory" << endl;
	abort(); //如果不终止程序，将一直重复调用该函数
}

int main(int argc, char *argv[]) {
	set_new_handler(noMoreMemory); //new 失败的时候会调用该函数

	int* p = new int[10000000000000000];
	assert(p);

	p = new int[100000000000000000];
	assert(p);

	return 0;
}