//给定一个排序数组和一个目标值，在数组中找到目标值，并返回其索引。如果目标值不存在于数组中，
//返回它将会被按顺序插入的位置。
#include<vector>

using namespace std;

class Solution {
public:
	int searchInsert(vector<int>& nums, int target) {
		if (target <= nums[0])return 0;

		int size = int(nums.size());
		for (int i = 1; i < size; ++i) {
			if (target <= nums[i])
				return i;
		}
		return size;
	}
};