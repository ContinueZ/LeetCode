#include<iostream>
#include<map>
#include<vector>
#include<string>

using namespace std;
class Solution {
	vector<string> result;
	map<char, string> store;
	string digits;
public:
	vector<string> letterCombinations(string digits) {
		if (digits.empty())
			return result;
		this->digits = digits;
		//存储字典
		store = map<char, string>{ { '2', "abc" }, { '3', "def" }, { '4', "ghi" }, { '5', "jkl" }, { '6', "mno" }, { '7', "pqrs" }, { '8', "tuv" }, { '9', "wxyz" } };
		dfs("", 0);

		return result;
	}
	void dfs(string resultStr, int index)
	{
		int digitSize = int(this->digits.size());
		//重点，相等的时候，就证明得到了一个结果，然后pushback进容器，并返回
		if (digitSize == index)
		{
			result.push_back(resultStr);
			return;
		}
		char targetChar = this->digits[index];
		string targetStr = store[targetChar];
		//最内层tmpChar后移到最后一位时，返回上一次继续循环
		for (auto tmpChar : targetStr)
		{
			//递归调用
			dfs(resultStr + tmpChar, index + 1);
		}
		return;
	}
};

int main()
{
	Solution s;
	vector<string> v = s.letterCombinations("2567");
	vector<string>::iterator it = v.begin();
	for (;it!=v.end();++it)
		cout << (*it) << endl;

	return 0;
}