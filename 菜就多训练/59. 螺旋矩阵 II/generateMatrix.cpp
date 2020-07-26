#include "..\include.h"

class Solution {
public:
	vector<vector<int>> generateMatrix(int n) {
		if (n == 0) return { {} };
		if (n == 1) return { {1} };

		vector<vector<int>> ans(n,vector<int>(n));
		int l = 0;
		int r = n - 1;
		int b = n - 1;
		int u = 0;
		int k = 1;
		while (l <= r&&u <= b) {
			int i = u;
			int j = l;
			while (j <= r&&k<=n*n) {
				ans[i][j] = k;
				++k;
				++j;
			}
			++u;
			i = u;
			j = r;
			while (i <= b && k <= n * n) {
				ans[i][j] = k;
				++k;
				++i;
			}
			--r;
			j = r;
			i = b;
			while (j >= l && k <= n * n) {
				ans[i][j] = k;
				++k;
				--j;
			}
			--b;
			i = b;
			j = l;
			while (i >= u && k <= n * n) {
				ans[i][j] = k;
				++k;
				--i;
			}
			++l;
			j = l;
			i = u;
		}
		return ans;
	}
};

int main()
{
	int n = 3;

	Solution s;
	vector<vector<int>> ans = s.generateMatrix(n);//commit test

	return 0;
}