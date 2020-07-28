#include "../include.h"
class Solution {
public:
	vector<string> split(const string& s, char delemiter) {
		vector<string> tokens;
		string token;
		istringstream tokenStream(s); //有红线，不影响编译
		while (getline(tokenStream, token, delemiter)) {
			if (token == "." || token == "" || (token == ".."&&tokens.size() == 0))
				continue;
			else if (token == ".."&&token.size() > 0)
				tokens.pop_back();
			else
				tokens.push_back(token);
		}
		return tokens;
	}
	string simplifyPath(string path) {
		string str = "";
		vector<string> tmp = split(path, '/');
		for (auto s : tmp) {
			str += "/";
			str += s;
		}
		return str == "" ? "/" : str;
	}
};

int main()
{
	string str = "/a//b////c/d//././/..";
	Solution s;
	string ans = s.simplifyPath(str);

	return 0;
}