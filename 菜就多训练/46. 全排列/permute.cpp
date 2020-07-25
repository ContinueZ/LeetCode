#include "..\..\include.h"

class Solution {
public:
	vector<vector<int>> permute(vector<int>& nums) {
		permuteHelp(nums, 0, nums.size()-1);
		return ans;
	}

	 void permuteHelp(vector<int>& nums, int s, int l) {
		if (s == l) {
			ans.push_back(nums);
		}
		else {
			for (int i = s; i <= l; ++i) {
				swap(nums[s], nums[i]);
				permuteHelp(nums, s + 1, l);
				swap(nums[s], nums[i]);
			}
		}
	}
private:
	vector<vector<int>> ans;
};

int main()
{
	vector<int> v{ 1,2,3 };

	Solution s;
	vector<vector<int>> ans = s.permute(v);

	return 0;
}