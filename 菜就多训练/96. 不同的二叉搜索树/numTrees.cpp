

#include<vector>
#include<iostream>
using namespace std;


//G(n): 长度为 n 的序列能构成的不同二叉搜索树的个数。
//F(i, n) : 以 i 为根、序列长度为 n 的不同二叉搜索树个数(1≤i≤n)。
//则有：
//F(i,n) = G(i-1)*G(n-i)
//G(n) = F(i,n)(i=1到n的累加)//所以G(n)= G(i - 1)*G(n - i)(i = 1到n的累加)

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