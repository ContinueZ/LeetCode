#include<vector>
#include<iostream>
#include<algorithm>
using namespace std;


class Solution {
public:
	vector<vector<int>> merge(vector<vector<int>>& intervals) {
		vector<vector<int>> res;
		if(intervals.empty())return res;
		
		auto cmp = [](vector<int> &v1, vector<int> &v2) {return v1[0] < v2[0]; };
		sort(intervals.begin(), intervals.end(), cmp);

		res.emplace_back(intervals[0]);
		for(int i = 1;i<intervals.size();++i){
			int bk = res.size() - 1;
			if (res[bk][1] >= intervals[i][0]) {
				if (res[bk][1] < intervals[i][1])
					res[bk][1] = intervals[i][1];
			}
			else {
				res.emplace_back(intervals[i]);
			}
		}
		return res;
	}
//private:
//	struct cmp{
//		bool operator()(vector<int> v1, vector<int> v2) {
//			return (v1[0] <= v2[0]);
//		}
//	};

};

int main()
{
	vector<vector<int>> v = { {1, 3},{2, 6},{8, 10},{15, 18} };
	Solution s;
	vector<vector<int>> res = s.merge(v);

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