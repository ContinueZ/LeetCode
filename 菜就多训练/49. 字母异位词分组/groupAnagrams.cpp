#include "..\..\include.h"

class Solution {
public:
	vector<vector<string>> groupAnagrams(vector<string>& strs) {

		vector<vector<string>> ans;
		unordered_map<string, vector<string>> m;
		for(auto& s : strs){
			string t = s;
			sort(t.begin(), t.end());
			m[t].push_back(s);
		}
		for (auto& n : m)
			ans.push_back(n.second);//pushbackµÄÔªËØÎªvector<string>

		return ans;
	}
};

int main()
{
	vector<string> v{ "eat", "tea", "tan", "ate", "nat", "bat" };

	Solution s;
	vector<vector<string>> ans = s.groupAnagrams(v);

	return 0;
}