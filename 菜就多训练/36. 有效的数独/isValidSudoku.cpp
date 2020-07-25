#include<iostream>
#include<vector>

using namespace std;


//------------------------------------9*9数独--------------------------------------
class Solution {
public:
	bool isValidSudoku(vector<vector<char>>& board) {

		int row[9][10] = { 0 };// 哈希表存储每一行的每个数是否出现过，默认初始情况下，每一行每一个数都没有出现过
        // 整个board有9行，第二维的维数10是为了让下标有9，和数独中的数字9对应。
		int col[9][10] = { 0 };
		int box[9][10] = { 0 };
		for (int i = 0; i < 9; ++i) {
			for (int j = 0; j < 9; ++j) {
				if (board[i][j] == '.')continue;
				int curnumber = board[i][j] - '0';
				if (row[i][curnumber])return false;
				if (col[j][curnumber])return false;
				//（i/3）*3+(j/3)计算当前[i][j]所以在盒子number
				if (box[(i / 3) * 3 + (j / 3)][curnumber])return false;

				//没出现过的都置1
				row[i][curnumber] = 1;
				col[j][curnumber] = 1;
				box[(i / 3) * 3 + (j / 3)][curnumber] = 1;	
			}
		}
		return true;
	}
};