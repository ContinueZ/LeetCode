#include "..\..\include.h"

class Solution {
public:
	//此题双指针无法实现
	//bool isInterleave(string s1, string s2, string s3) {
	//	size_t n1 = s1.size();
	//	size_t n2 = s2.size();

	//	int i = 0, j = 0,k = 0;
	//	while (i < n1&&j < n2) {
	//		if (s3[k] == s1[i]) {
	//			++i;
	//		}
	//		else if (s3[k] == s2[j]) {
	//			++j;
	//		}
	//		else
	//			return false;
	//		++k;
	//	}
	//	if (i >= n1) {
	//		if (s2.substr(j, n2-j-1) == s3.substr(k, n1 + n2 - k-1))return true;
	//	}
	//	if (j >= n2) {
	//		if (s1.substr(i, n1-i-1) == s3.substr(k, n1 + n2 - k-1))return true;
	//	}

	//	return false;
	//}

	bool isInterleave(string s1, string s2, string s3) {
		//vector<vector<int>> f(s1.size()+1, vector<int>(s2.size()+1, false));

		int n = s1.size();
		int m = s2.size();
		int t = s3.size();
		if (n + m != t)return false;

		auto f = vector<int>(m + 1, false);
		f[0] = true;
		
		for (int i = 0; i <= n; ++i) {
			for (int j = 0; j <= m; ++j) {
				int p = i + j - 1;
				if (i > 0) {
					//f[i][j] |= (f[i - 1][j] && s1[i - 1] == s3[p]);
					f[j] &= (s1[i - 1] == s3[p]);//f[i][j]之和f[i-1][j]有关
				}
				if (j > 0) {
					//f[i][j] |= (f[i][j-1] && s2[j - 1] == s3[p]);
					f[j] |= f[j - 1] && (s2[j - 1] == s3[p]);
				}
			}
		}
		return f[m];
	}
};

int main()
{
	string s1 = "aabcc", s2 = "dbbca", s3 = "aadbbcbcac";

	Solution s;
	bool ans = s.isInterleave(s1,s2,s3);
	cout << ans << endl;
	return 0;
}