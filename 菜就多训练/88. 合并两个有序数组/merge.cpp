//��������������������?nums1 �� nums2���� nums2 �ϲ���?nums1?�У�ʹ��?num1 ��Ϊһ���������顣
//
//˵�� :
//
//��ʼ��?nums1 �� nums2 ��Ԫ�������ֱ�Ϊ?m �� n��
//����Լ���?nums1?���㹻�Ŀռ䣨�ռ��С���ڻ����?m + n�������� nums2 �е�Ԫ�ء�

#include<vector>
#include<algorithm>
using namespace std;
class Solution {
public:
	void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
		for (int i = m, j = 0; i < m + n, j < n; ++i, ++j)
			nums1[i] = nums2[j];
		sort(nums1.begin(),nums1.end());
	}
};