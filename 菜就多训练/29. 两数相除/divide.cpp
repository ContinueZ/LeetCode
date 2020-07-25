//被除数和除数均为 32 位有符号整数。
//除数不为?0。
//假设我们的环境只能存储 32 位有符号整数，其数值范围是[?2^31, 2^31?? 1]。本题中，如果除法结果溢出，
//则返回 2^31?? 1。
//关于如何提高效率快速逼近结果
//举个例子：11 除以 3 。
//首先11比3大，结果至少是1， 然后我让3翻倍，就是6，发现11比3翻倍后还要大，那么结果就至少是2了，
//那我让这个6再翻倍，得12，11不比12大，吓死我了，差点让就让刚才的最小解2也翻倍得到4了。
//但是我知道最终结果肯定在2和4之间。也就是说2再加上某个数，这个数是多少呢？我让11减去刚才最后一次的结果6，
//剩下5，我们计算5是3的几倍，也就是除法，看，递归出现了。
//说得很乱，不严谨，大家看个大概，然后自己在纸上画一画，或者直接看我代码就好啦！
#include<iostream>
class Solution {
public:
	int divide(int dividend, int divisor) {
		if (dividend == 0)return 0;
		if (divisor == 1)return dividend;
		if (divisor == -1) {
			if (dividend > INT_MIN)return -dividend;//只要不是最小的那个整数，都返回相反数
			return INT_MAX;  //如果是最小的整数，则返回最大的
		}

		long a = dividend;
		long b = divisor;
		int sign = 1;
		if ((a < 0 && b > 0) || (a > 0 && b < 0))
			sign = -1;

		a = a > 0 ? a : -a;
		b = b > 0 ? b : -b;
		long res = div(a, b);
		if (sign > 0)return res > INT_MAX ? INT_MAX : res;
		return -res;

	}

	int div(long a, long b) {
		if (a < b)return 0;
		long count = 1;
		long tb = b;
		while ((tb + tb) <= a) {
			count = count + count;
			tb = tb + tb;
		}
		return count + div(a - tb, b);
	}
};

int main()
{
	Solution s;
	int ret = s.divide(9, 3);

	std::cout << ret << std::endl;
	return 0;
}