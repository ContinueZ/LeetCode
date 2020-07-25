#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class Solution {
public:
	vector<vector<int>> fourSum(vector<int>& nums, int target) {
		
		int numsSize = int(nums.size());
		vector<vector<int>> result;
		if (numsSize <= 3)
			return result;
		sort(nums.begin(), nums.end());
		int a, b, c, d;

		for (a = 0; a <= numsSize - 4; ++a)
		{
			if (a > 0 && nums[a] == nums[a - 1])continue;
			for (b = a + 1; b <= numsSize - 3; ++b)
			{
				if (b > a + 1 && nums[b] == nums[b - 1])continue;
				c = b + 1;
				d = numsSize - 1;
				while (c < d)
				{
					if (nums[a] + nums[b] + nums[c] + nums[d] == target)
					{
						result.push_back({ nums[a] , nums[b] , nums[c] , nums[d] });
						//去重复
						while (c < d&&nums[c] == nums[++c]) {};
						while (c < d&&nums[d] == nums[--d]) {};
					}
					else if (nums[a] + nums[b] + nums[c] + nums[d] < target)
						++c;
					else
						--d;
				}
			}
		}
		return result;
	}
};

int main()
{
	Solution s;
	vector<int> v = { 1, 0, -1, 0, -2, 2 };
	int target = 0;
	vector<vector<int>> ret = s.fourSum(v, target);

	int retSize = int(ret.size());
	int i, j;

	//打印二维vector
	cout << '[';
	for (i = 0; i < retSize; ++i)
	{
		cout << '[';
		for (j = 0; j < 4 - 1; ++j)
		{
			cout << ret[i][j] << ',';
		}
		cout << ret[i][j] << ']';
		if (i < retSize - 1)
			cout << ',';
	}
	cout << ']' << endl;

	return 0;
}