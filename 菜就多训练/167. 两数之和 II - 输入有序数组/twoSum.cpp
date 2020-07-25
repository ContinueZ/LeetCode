#include "..\..\include.h"

class Solution {
public:
	vector<int> twoSum(vector<int>& numbers, int target) {
		int n = numbers.size();
		map<int, int> m;

		int i = 0, j = n - 1;
		while (i < j) {
			if (numbers[i] + numbers[j] > target)--j;
			else if (numbers[i] + numbers[j] < target)++i;
			else return { i + 1,j + 1 };
		}
		return {};
	}
};

int main()
{
	vector<int> v{ 1,2,3 };
	int t = 4;

	Solution s;
	vector<int> ans = s.twoSum(v, t);

	return 0;
}