#include<vector>
using namespace std;

class Solution {
public:
	void sortColors(vector<int>& nums) {
		int n = static_cast<int>(nums.size());
		if (n < 2)return;

		int p0 = 0;
		int cur = 0;
		int p2 = n - 1;
		while (cur < p2) {
			while (nums[p0] == 0) {
				++p0;
				++cur;
			}
			while (nums[p2] == 2)--p2;

		}
	}
};