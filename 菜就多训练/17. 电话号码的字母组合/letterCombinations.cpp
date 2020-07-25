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
		//�洢�ֵ�
		store = map<char, string>{ { '2', "abc" }, { '3', "def" }, { '4', "ghi" }, { '5', "jkl" }, { '6', "mno" }, { '7', "pqrs" }, { '8', "tuv" }, { '9', "wxyz" } };
		dfs("", 0);

		return result;
	}
	void dfs(string resultStr, int index)
	{
		int digitSize = int(this->digits.size());
		//�ص㣬��ȵ�ʱ�򣬾�֤���õ���һ�������Ȼ��pushback��������������
		if (digitSize == index)
		{
			result.push_back(resultStr);
			return;
		}
		char targetChar = this->digits[index];
		string targetStr = store[targetChar];
		//���ڲ�tmpChar���Ƶ����һλʱ��������һ�μ���ѭ��
		for (auto tmpChar : targetStr)
		{
			//�ݹ����
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