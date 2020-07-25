//给定一个整数数组 nums ，找到一个具有最大和的连续子数组（子数组最少包含一个元素），返回其最大和。
#include<vector>
using namespace std;

class Solution {
public:
	int maxSubArray(vector<int>& nums) {
		int size = int(nums.size());
		int max = INT_MIN;
		for (int i = 0; i < size; ++i) {
			int sum = 0;
			for (int j = i; j < size; ++j) {
				sum += nums[j];
				if (sum > max)
					max = sum;
			}
		}
		return max;
	}
};