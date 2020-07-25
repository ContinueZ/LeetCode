#include<iostream>
#include<string>
#include<vector>
using namespace std;

class Solution {
public:
	string longestCommonPrefix(vector<string>& strs) {

		int strsLen = strs.size();
		if (strsLen == 0)
			return "";
		if (strsLen == 1)
			return strs.at(0);

		int j = 0;
		while (1)
		{
			for (int i = 0; i < strsLen; ++i)
			{
				if (j >= strs.at(i).size())
					return strs.at(i).substr(0, j);

				char c = strs.at(0).at(j);
				if (c != strs.at(i).at(j))
					return strs.at(i).substr(0, j);
			}
			++j;
		}
	}
};

int main()
{
	vector<string> strs = { "flefds","fleitghti","flehinng" };
	Solution s;
	string str = s.longestCommonPrefix(strs);
	cout << str << endl;

	return 0;
}