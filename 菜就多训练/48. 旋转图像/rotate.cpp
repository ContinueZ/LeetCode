//����һ�� n?��?n �Ķ�ά�����ʾһ��ͼ��
//
//��ͼ��˳ʱ����ת 90 �ȡ�
//
//˵����
//
//�������ԭ����תͼ������ζ������Ҫֱ���޸�����Ķ�ά�����벻Ҫʹ����һ����������תͼ��
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
		// s����ת��ʼλ�ã�l�Ǿ���ߴ��һ
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