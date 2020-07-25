#include "..\..\include.h"

class Solution {
public:
	string getPermutation(int n, int k) {
		int i = 1;
		string s = "";
		while (i <= n) {
			s += (i + '0');
			++i;
		}
		int j = 1;
		do {
			if (j != k)++j;
			else break;
		} while (next_permutation(s.begin(), s.end()));
		return s;
	}
};

int main()
{
	Solution s;
	string ans = s.getPermutation(3, 3);
	cout << ans << endl;

	return 0;
}