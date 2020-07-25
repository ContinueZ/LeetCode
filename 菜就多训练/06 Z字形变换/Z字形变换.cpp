#include<iostream>
#include<string>
//#include<vector>
using namespace std;

class Solution {
public:
	string convert(string s, int numRows) {
		int tmp = 0;
		string str[1024];
		//vector<string> str;
		string ret;
		if (numRows == 1)
			return s;
		for (int i = 0; i < s.size(); i++)
		{
			if (tmp == numRows)
			{
				tmp = tmp - 2;
				while (tmp >= 0 && i < s.size())
				{
					str[tmp--] += s[i];
					i++;
				}	
			}
			if (tmp < 0)
				tmp = tmp + 2;
			if(i < s.size())
				str[tmp++] += s[i];
		}
		for (int j = 0; j < numRows; j++)
			ret += str[j];

		return ret;
	}
};

int main()
{
	Solution s;
	string str("LEETCODEISHIRING");
	string ret = s.convert(str, 3);
	cout << ret << endl;
	return 0;
}