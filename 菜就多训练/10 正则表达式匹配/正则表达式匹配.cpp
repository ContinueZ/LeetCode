#include<iostream>
#include<string>

class Solution {
public:
	bool isMatch(std::string s, std::string p) {
		if (p.empty())
			return s.empty();

		bool first_match = (s[0] == p[0]) || (p[0] == '.');

		if (p.size() >= 2 && p[1] == '*')
		{
			if (s.empty())
				//s为空，p中当前*匹配前一个字符0次，然后跳过*,再与空字符串s进行匹配
				return isMatch(s, p.substr(2));
			else
				//解释：如果发现有字符和 '*' 结合，
				//或者匹配该字符 0 次，然后跳过该字符和 '*'
				//或者当 p[0] 和 s[0] 匹配后，移动 s
				return isMatch(s, p.substr(2)) || (first_match && isMatch(s.substr(1), p));

		}
		else
		{
			if (s.empty())
				return false;
			else
			{
				return first_match && isMatch(s.substr(1), p.substr(1));
			}
		}

	}
};

int main()
{
	Solution s;
	bool b = s.isMatch("mississippi", "mis*is*p*.");
	if (b)
		std::cout << "匹配\n";
	else
		std::cout << "不匹配\n";

	return 0;
}