//����һ���������� nums ���ҵ�һ���������͵����������飨���������ٰ���һ��Ԫ�أ������������͡�
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