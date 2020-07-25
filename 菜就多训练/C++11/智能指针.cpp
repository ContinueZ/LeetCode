#include<iostream>
#include<memory>
using namespace std;

bool IsRvalue(const int&&)
{
	return true;
}

bool IsRvalue(int &)
{
	return false;
}

bool IsRvalue(const int&)
{
	return false;
}

//bool IsRvalue(int )
//{
//    return false;
//}


void Test(int &&rv)
{
	printf("rv is a rvalue: %s\n", IsRvalue(rv) ? "yes" : "no");
	printf("rv is a move(rvalue): %s\n", IsRvalue(move(rv)) ? "yes" : "no");
}

int main()
{
	//const unique_ptr<int> ptr(new int(2));
	////const的表达式只能被一下两种形式绑定
	//const unique_ptr<int>&& new_ptr = move(ptr);	
	//const unique_ptr<int>& new_ptr = move(ptr);

	//unique_ptr<int> new_ptr = move(ptr);
	//cout << *new_ptr << endl;

	int i = 5;
	Test(move(i));
	system("pause");
	return 0;
	
	return 0;
}