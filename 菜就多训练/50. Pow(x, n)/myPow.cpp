#include "..\..\include.h"

class Solution {
public:
	double myPow(double x, int n) {
		long long N = n;
		return N >= 0 ? quickMul(x, N) : 1.0 / quickMul(x, -N);
	}

	double quickMul(double x, long long N) {
		if (N == 0)
			return 1.0;
		double y = quickMul(x, N / 2);
		return N % 2 == 0 ? y * y : y * y * x;
	}
};

int main()
{
	Solution s;
	double x = 0;
	int n = -3;
	double ans = s.myPow(x,n);

	cout << ans << endl;

	return 0;
}