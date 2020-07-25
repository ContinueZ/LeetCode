#include "..\..\include.h"

class Solution {
public:
	int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
		int n = obstacleGrid.size();
		int m = obstacleGrid[0].size();

		//vector<vector<int>> f(n+1, vector<int>(m+1, 0));//多申请一行一列空间
		vector<int> f(m);

		f[0] = (obstacleGrid[0][0] == 0);
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < m; ++j) {
				if (obstacleGrid[i][j] == 1) {		
					f[j] = 0;
					continue;
				}
				if ((j-1 >= 0) && obstacleGrid[i][j]==0) {
					f[j] += f[j-1];
				}
			}
		}

		return f[m-1];
	}
};

int main()
{
	vector<vector<int>> v{
	{0, 0, 0},
	{0, 1, 0},
	{0, 0, 0}};

	Solution s;
	int ans = s.uniquePathsWithObstacles(v);
	cout << ans << endl;

	return 0;
}