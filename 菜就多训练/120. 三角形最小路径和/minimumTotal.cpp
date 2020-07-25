//[
//	[2],
//	[3, 4],
//	[6, 5, 7],
//	[4, 1, 8, 3]
//]
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
	int minimumTotal(vector<vector<int>>& triangle) {
		int n = triangle.size(), m = triangle[n - 1].size();
		vector<int> ans(triangle[n-1]);
		for(int i = n-2; i >= 0; --i)//反向
			for (int j = 0; j <= i; j++) {
				//每次获得两个分支路径和相对小的
				int imin = min(ans[j] + triangle[i][j], ans[j + 1]+triangle[i][j]);
				ans[j] = imin;
			}
		return ans[0];
	}
};

int main()
{
	vector<vector<int>> v{ {2} ,{3,4},{6,5,7},{4,1,8,3} };
	Solution s;
	int ret = s.minimumTotal(v);
	cout << ret << endl;

	return 0;
}