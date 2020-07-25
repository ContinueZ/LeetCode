#include<iostream>
#include<vector>

using namespace std;


//------------------------------------9*9����--------------------------------------
class Solution {
public:
	bool isValidSudoku(vector<vector<char>>& board) {

		int row[9][10] = { 0 };// ��ϣ��洢ÿһ�е�ÿ�����Ƿ���ֹ���Ĭ�ϳ�ʼ����£�ÿһ��ÿһ������û�г��ֹ�
        // ����board��9�У��ڶ�ά��ά��10��Ϊ�����±���9���������е�����9��Ӧ��
		int col[9][10] = { 0 };
		int box[9][10] = { 0 };
		for (int i = 0; i < 9; ++i) {
			for (int j = 0; j < 9; ++j) {
				if (board[i][j] == '.')continue;
				int curnumber = board[i][j] - '0';
				if (row[i][curnumber])return false;
				if (col[j][curnumber])return false;
				//��i/3��*3+(j/3)���㵱ǰ[i][j]�����ں���number
				if (box[(i / 3) * 3 + (j / 3)][curnumber])return false;

				//û���ֹ��Ķ���1
				row[i][curnumber] = 1;
				col[j][curnumber] = 1;
				box[(i / 3) * 3 + (j / 3)][curnumber] = 1;	
			}
		}
		return true;
	}
};