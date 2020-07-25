//����һ������ n ������������?nums���ж�?nums?���Ƿ��������Ԫ�� a��b��c ��
//ʹ��?a + b + c = 0 ���ҳ��������������Ҳ��ظ�����Ԫ�顣
//
//ע�⣺���в����԰����ظ�����Ԫ�顣

#include<vector>
#include<map>
#include<iostream>
#include<algorithm>

using namespace std;

class Solution {
public:
	vector<vector<int>> threeSum(vector<int>& nums) {
		vector<vector<int>> relt;
		int N = nums.size();
		if (N <= 2)
			return relt;

		sort(nums.begin(), nums.end());
		for (int index = 0; index <= N - 2; ++index)
		{
			int lo = index + 1;
			int hi = N - 1;
			int intnow = nums[index];

			if (intnow > 0)
				break;

			while (lo < hi)
			{
				int intlo = nums[lo];
				int inthi = nums[hi];
				if (intlo + inthi == -intnow)
				{
					relt.push_back({ intnow,intlo,inthi });
					while (lo < hi&&nums[++lo] == intlo) {}
					while (lo < hi&&nums[--hi] == inthi) {}
				}
				else if (intlo + inthi < -intnow)
				{
					++lo;
				}
				else if (intlo + inthi > -intnow)
					--hi;
			}
			while (((index + 1) < (N - 2)) && nums[index] == nums[index + 1]) { ++index; }

		}

		return relt;
	}
};

int main()
{
	vector<int> nums = { -1, 0, 1, 2, -1, -4 };
	Solution s;
	vector<vector<int>> vRslt = s.threeSum(nums);
	int i = 0, j = 0;
	cout << '[';
	for (i = 0; i < vRslt.size(); ++i)
	{
		cout << '[';
		for (j = 0; j < vRslt[i].size()-1; ++j)
		{
			cout << vRslt[i][j] << ',';
		}
		cout << vRslt[i][j] << ']';
		if (i < vRslt.size() - 1)
			cout << ',';
	}
	cout << ']' << endl;
	
	return 0;
}