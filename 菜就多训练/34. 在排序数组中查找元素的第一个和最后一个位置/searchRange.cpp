//����һ�������������е��������� nums����һ��Ŀ��ֵ target���ҳ�����Ŀ��ֵ�������еĿ�ʼλ�úͽ���λ�á�
//
//����㷨ʱ�临�Ӷȱ�����?O(log n) ����
//
//��������в�����Ŀ��ֵ������?[-1, -1]��
#include<vector>
using namespace std;
class Solution {
public:
	vector<int> searchRange(vector<int>& nums, int target) {
		auto it = find(nums.begin(), nums.end(), target);
		if (it != nums.end()) {
			int n = count(nums.begin(), nums.end(), target);
			return { it - nums.begin(),it - nums.begin() + n - 1 };
		}
		else return { -1,-1 };
	}
};