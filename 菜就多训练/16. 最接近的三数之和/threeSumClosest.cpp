#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class Solution {
public:
	int threeSumClosest(vector<int>& nums, int target) {
		int N = nums.size();
		int gap = INT_MAX;
		int sum = 0;
		if (N <= 2)
			return sum;
		sort(nums.begin(), nums.end());
		for (int index = 0; index < N - 2; ++index)
		{
			int now = index;
			int lo = index + 1;
			int hi = N - 1;
			int intnow = nums[now];

			while (lo < hi)
			{
				int intlo = nums[lo];
				int inthi = nums[hi];
				
				int newgap = abs(target - (intnow + intlo + inthi));
				
				if (intnow + intlo + inthi == target)
					return target;
				if (intnow + intlo + inthi < target)
				{
					if (gap > newgap)
					{
						gap = newgap;
						sum = intnow + intlo + inthi;
					}
					//这里一定要注意，不能写成nums[lo++],否则lo会多加一次
					while (lo < N&&intlo == nums[lo]) { lo++; }
				}
				else if (intnow + intlo + inthi > target)
				{
					if (gap > newgap)
					{
						gap = newgap;
						sum = intnow + intlo + inthi;
					}
					//这里一定要注意，不能写成nums[hi--],否则hi会多减一次
					while (hi >= 0 && inthi == nums[hi]) { hi--; }
				}
			}
			while (((index + 1) < (N - 2)) && nums[index] == nums[index + 1])
				++index;
		}

		return sum;

	}
};

int main()
{
	Solution s;
	vector<int> v = { 0,2,1,-3 };
	int target = 1;
	int ret = s.threeSumClosest(v, target);
	cout << "result = " << ret << endl;

	return 0;
}