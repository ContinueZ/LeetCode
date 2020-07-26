#include "..\include.h"
class Solution {
public:
	bool canJump(vector<int>& nums) {
		int n = nums.size();
		int farmost = 0;
		for (int i = 0; i < n; ++i) {
			if (i <= farmost) {
				farmost = max(farmost, i + nums[i]);
				if (farmost >= n - 1)return true;
			}
			else return false;
		}
		return true;
	}
};

int main()
{
	vector<int> v{ 1,2,3 };

	Solution s;
	bool ans = s.canJump(v);

	return 0;
}