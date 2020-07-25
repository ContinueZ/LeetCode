#include "..\..\include.h"

class Solution {
public:
	int climbStairs(int n) {
		/*if (n == 0||n == 1)return 1;
		return climbStairs(n - 1) + climbStairs(n - 2);*/
		int p = 0, q = 0, r = 1;
		for (int i = 0; i < n; ++i) {
			p = q;
			q = r;
			r = p + q;
		}
		return r;
	}
};

int main()
{
	int n = 10;

	Solution s;
	int ans = s.climbStairs(n);
	cout << ans << endl;
	return 0;
}