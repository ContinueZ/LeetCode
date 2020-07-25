#include "..\..\include.h"

class Solution {
private:
	vector<int> val;
	vector<vector<int>> rec;
public:
	int maxCoins(vector<int>& nums) {
		int n = nums.size();

		val.resize(n + 2);
		val[0] = val[n + 1] = 1;
		for (int i = 1; i <= n; ++i) {
			val[i] = nums[i - 1];
		}
		rec.resize(n + 2, vector<int>(n + 2, -1));

		return solve(0, n + 1);
	}

	//left，right是不使用
	int solve(int left, int right) {

		if (left >= right - 1)
			return 0;

		//可能会有前面填入的结算好的数据，直接返回使用
		if (rec[left][right] != -1)
			return rec[left][right];

		for (int i = left+1; i < right; ++i) {
			int sum = val[left] * val[i] * val[right];
			sum += solve(left, i) + solve(i, right);
			rec[left][right] = max(rec[left][right], sum);
		}

		return rec[left][right];
	}
};

int main()
{
	vector<int> v{ 3,1,5,8 };

	Solution s;
	int ans = s.maxCoins(v);
	cout << ans << endl;
	return 0;
}