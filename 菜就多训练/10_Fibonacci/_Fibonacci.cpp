#include<iostream>

int Fibonacci(int n)
{
	if(n <= 0)
		return 0;
	if (n == 1)
		return 1;
	return Fibonacci(n - 1) + Fibonacci(n - 2);

}

int main()
{
	int n = Fibonacci(5);
	std::cout << n << std::endl;
}