//����һ�����������һ��Ŀ��ֵ�����������ҵ�Ŀ��ֵ�������������������Ŀ��ֵ�������������У�
//���������ᱻ��˳������λ�á�
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