//给定一个包含 n 个整数的数组?nums，判断?nums?中是否存在三个元素 a，b，c ，
//使得?a + b + c = 0 ？找出所有满足条件且不重复的三元组。
//
//注意：答案中不可以包含重复的三元组。

#include<vector>
#include<map>
#include<iostream>
#include<algorithm>

using namespace std;

class Solution {
public:
	vector<vector<int>> threeSum(vector<int>& nums) {
		vector<vector<int>> relt;
		int N = nums.size();
		if (N <= 2)
			return relt;

		sort(nums.begin(), nums.end());
		for (int index = 0; index <= N - 2; ++index)
		{
			int lo = index + 1;
			int hi = N - 1;
			int intnow = nums[index];

			if (intnow > 0)
				break;

			while (lo < hi)
			{
				int intlo = nums[lo];
				int inthi = nums[hi];
				if (intlo + inthi == -intnow)
				{
					relt.push_back({ intnow,intlo,inthi });
					while (lo < hi&&nums[++lo] == intlo) {}
					while (lo < hi&&nums[--hi] == inthi) {}
				}
				else if (intlo + inthi < -intnow)
				{
					++lo;
				}
				else if (intlo + inthi > -intnow)
					--hi;
			}
			while (((index + 1) < (N - 2)) && nums[index] == nums[index + 1]) { ++index; }

		}

		return relt;
	}
};

int main()
{
	vector<int> nums = { -1, 0, 1, 2, -1, -4 };
	Solution s;
	vector<vector<int>> vRslt = s.threeSum(nums);
	int i = 0, j = 0;
	cout << '[';
	for (i = 0; i < vRslt.size(); ++i)
	{
		cout << '[';
		for (j = 0; j < vRslt[i].size()-1; ++j)
		{
			cout << vRslt[i][j] << ',';
		}
		cout << vRslt[i][j] << ']';
		if (i < vRslt.size() - 1)
			cout << ',';
	}
	cout << ']' << endl;
	
	return 0;
}