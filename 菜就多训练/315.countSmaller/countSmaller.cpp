#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
	//������
	//vector<int> countSmaller(vector<int>& nums) {
	//	vector<int> res;
	//	size_t size = nums.size();
	//	if (size == 0)return res;
	//	
	//	if (size == 1) {
	//		res.push_back(0);
	//		return res;
	//	}

	//	
	//	for (int i = 0; i < size; ++i){
	//		int count_i = 0;
	//		for (int j = i + 1; j < size; ++j) {
	//			if (nums[i] > nums[j])
	//				++count_i;
	//		}
	//		res.push_back(count_i);
	//		
	//	}
	//	return res;
	//}

	vector<int> countSmaller(vector<int>& nums) {
		vector<int> sorted_nums;
		vector<int> res;

		for (int i = nums.size() - 1; i >= 0; --i) {
			 //��[,)��Χ���ص�һ����С��Ŀ��ֵԪ�صĵ�����
			auto iter = lower_bound(sorted_nums.begin(), sorted_nums.end(), nums[i]);
			//��������ȥ��һ��Ԫ�صĵ�����������nums��С�ڸ�Ԫ�صĸ���
			int pos = iter - sorted_nums.begin();
			//��������Ԫ�أ�Ϊ�����ж���׼��
			sorted_nums.insert(iter, nums[i]);
			//����push��res
			res.push_back(pos);
		}
		//��Ϊ������ģ�����ʹ��reverse��������һ��
		reverse(res.begin(), res.end());
		return res;
	}
};

int main()
{

	vector<int> v{ 5,3,8,5,3,7,2,0 };
	Solution s;
	vector<int> res = s.countSmaller(v);
	for (auto i : res)
		cout << i << endl;
	return 0;
}