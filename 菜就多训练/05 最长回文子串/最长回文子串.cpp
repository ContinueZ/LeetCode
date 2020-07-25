#include<iostream>
#include<string>
using namespace std;

class Solution {
public:
	string longestPalindrome(string s) {

		if (s.length() == 1)
			return s;

		string rev = s;//用来存放s的反转字符串
		string temp;//用来临时存放回文字符串
		reverse(rev.begin(), rev.end());
		if (s == rev) return s;

		string q;//存放最长回文字符串
		int len = 0;//存放回文字符串的长度

		for (int i = 0; i < s.length(); i++)
		{
			for (int j = i; j < s.length(); j++)
			{
				temp += s[j];
				if (len >= temp.length())
					continue;
				else if (rev.find(temp) != -1)
				{
					string p = temp;
					reverse(p.begin(), p.end());
					if (p == temp)
					{
						len = temp.length();
						q = temp;
					}
				}
				else
					break;

			}
			temp = "";
		}
		return q;
	}
};

int main()
{
	Solution s;
	string str("aacdefcaa");
	string ret = s.longestPalindrome(str);
	cout << ret << endl;

	return 0;
}