

//������õ�new handlerֻ������ѡ��
//1.�ø���memory����
//2.����abort��������exit����

#include <iostream>
#include<cassert>
using namespace std;

void noMoreMemory() {
	cerr << "out of memory" << endl;
	abort(); //�������ֹ���򣬽�һֱ�ظ����øú���
}

int main(int argc, char *argv[]) {
	set_new_handler(noMoreMemory); //new ʧ�ܵ�ʱ�����øú���

	int* p = new int[10000000000000000];
	assert(p);

	p = new int[100000000000000000];
	assert(p);

	return 0;
}