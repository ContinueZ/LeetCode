//给定一个 n?×?n 的二维矩阵表示一个图像。
//
//将图像顺时针旋转 90 度。
//
//说明：
//
//你必须在原地旋转图像，这意味着你需要直接修改输入的二维矩阵。请不要使用另一个矩阵来旋转图像。
#include<vector>
#include<queue>
#include<iostream>
using namespace std;
class Solution {
public:
	void rotate(vector<vector<int>>& matrix) {
		int n = int(matrix.size());
		if (n == 1)
			return;
		else {

			for (int i = 0; i < n / 2; ++i) {
				move(matrix, i, n - 1);
			}
		}
	}
	
	void move(vector<vector<int>>& matrix, int k, int n) {
		// s是旋转起始位置，l是矩阵尺寸减一
		int i = k, j;
		int tmp, prev;

		for (int s = k; s < n - k; ++s) {
			j = s;
			prev = matrix[i][j];
			do {
				tmp = i;
				i = j;
				j = n - tmp;

				tmp = matrix[i][j];
				matrix[i][j] = prev;
				prev = tmp;

			} while (k != i || s != j);
		}
	}
};

int main()
{
	vector<vector<int>> v = { 
		{5, 1, 9, 11},
		{2, 4, 8, 10},
		{13, 3, 6, 7},
		{15, 14, 12, 16} 
	};
	Solution s;
	s.rotate(v);
	int i, j;
	for (i = 0; i < v.size(); ++i)
	{
		cout << '[';
		for (j = 0; j < v[i].size() - 1; ++j)
		{
			cout << v[i][j] << ',';
		}
		cout << v[i][j] << ']';
		if (i < v.size() - 1)
			cout << ',';
	}

	
}