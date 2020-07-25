

#include<vector>
#include<iostream>
using namespace std;


//G(n): ����Ϊ n �������ܹ��ɵĲ�ͬ�����������ĸ�����
//F(i, n) : �� i Ϊ�������г���Ϊ n �Ĳ�ͬ��������������(1��i��n)��
//���У�
//F(i,n) = G(i-1)*G(n-i)
//G(n) = F(i,n)(i=1��n���ۼ�)//����G(n)= G(i - 1)*G(n - i)(i = 1��n���ۼ�)

//G[0] = 1;
//G[1] = 1;
//---- > 2 <= i <= n, 1 = < j <= i


class Solution {
public:
	int numTrees(int n) {
		vector<int> G(n+1,0);
		G[0] = 1;
		G[1] = 1;
		for (int i = 2; i <= n; i++) {
			for (int j = 1; j <= i; ++j)
				G[i] += G[j - 1] * G[i - j];
		}
		return G[n];
	}
};

int main()
{
	Solution s;
	int ret = s.numTrees(4);
	cout << ret << endl;

	return 0;
}