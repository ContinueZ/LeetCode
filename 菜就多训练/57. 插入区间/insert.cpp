#include<vector>
#include<algorithm>
#include<iostream>
using namespace std;

class Solution {
public:
	vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
		vector<vector<int>> res;
		auto it = intervals.begin();

		for (; it != intervals.end() && newInterval[0] > (*it)[1]; ++it)
			res.emplace_back(*it);
		for (; it != intervals.end() && newInterval[1] >= (*it)[0]; ++it)
			newInterval = { min(newInterval[0],(*it)[0]),max(newInterval[1],(*it)[1]) };
		res.emplace_back(newInterval);
		res.insert(res.end(),it, intervals.end());

		return res;

	}
};

int main()
{
	vector<vector<int>> v = { {1, 3},{2, 6},{8, 10},{15, 18} };
	vector<int> v1 = { 2,9 };
	Solution s;
	vector<vector<int>> res = s.insert(v,v1);

	int i, j;
	for (i = 0; i < res.size(); ++i)
	{
		cout << '[';
		for (j = 0; j < res[i].size() - 1; ++j)
		{
			cout << res[i][j] << ',';
		}
		cout << res[i][j] << ']';
		if (i < res.size() - 1)
			cout << ',';
	}

	return 0;
}