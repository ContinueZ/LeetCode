//给定一个包含 m x n 个元素的矩阵（m 行, n 列），请按照顺时针螺旋顺序，返回矩阵中的所有元素。

#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
	vector<int> spiralOrder(vector<vector<int>>& matrix) {

		int m = matrix.size();
		if (!m)return {};
		int n = matrix[0].size();
		vector<int> ans;

		int l = 0, r = n - 1, u = 0, b = m - 1;
		while (l <= r && u <= b) {
			for (int j = l; j <= r; ++j) {
				ans.push_back(matrix[u][j]);
			}
			++u;
			if (u > b)break;
			for (int i = u; i <= b; ++i) {
				ans.push_back(matrix[i][r]);
			}
			--r;
			if (r < l)break;
			for (int j = r; j >= l; --j) {
				ans.push_back(matrix[b][j]);
			}
			--b;
			if (b < u)break;
			for (int i = b; i >= u; --i) {
				ans.push_back(matrix[i][l]);
			}
			++l;
			if (l > r)break;
		}

		return ans;
	}
};

int main()
{
	vector<vector<int>> v{
	{1, 2, 3, 4},
	{5, 6, 7, 8},
	{9,10,11,12}};

	Solution s;
	vector<int> ans = s.spiralOrder(v);

	return 0;
}