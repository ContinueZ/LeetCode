//ʵ�ֻ�ȡ��һ�����еĺ������㷨��Ҫ���������������������г��ֵ�������һ����������С�
//
//�����������һ����������У��������������г���С�����У����������У���
//
//����ԭ���޸ģ�ֻ����ʹ�ö��ⳣ���ռ䡣
//
//������һЩ���ӣ�����λ������У�����Ӧ���λ���Ҳ��С�
//1, 2, 3 �� 1, 3, 2
//3, 2, 1 �� 1, 2, 3
//1, 1, 5 �� 1, 5, 1

#include<vector>
#include<algorithm>
using namespace std;
class Solution {
public:
	void nextPermutation(vector<int>& nums) {
		next_permutation(nums.begin(),nums.end());
	}
};