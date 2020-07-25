#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
	//暴力法
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
			 //在[,)范围返回第一个不小于目标值元素的迭代器
			auto iter = lower_bound(sorted_nums.begin(), sorted_nums.end(), nums[i]);
			//迭代器减去第一个元素的迭代器，就是nums中小于该元素的个数
			int pos = iter - sorted_nums.begin();
			//按序插入该元素，为后续判断做准备
			sorted_nums.insert(iter, nums[i]);
			//个数push到res
			res.push_back(pos);
		}
		//因为是逆序的，所以使用reverse函数逆序一下
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