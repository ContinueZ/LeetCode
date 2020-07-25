#include<iostream>
#include<string>
#include<map>
#include<unordered_map>
using namespace std;

class Solution {
public:
	string intToRoman(int num) {
		if (num < 1 || num>3999)
			return "数字超出范围！无法计算！";
			
		map<int, string> mapRom = { {1,"I"},{4,"IV"},{5,"V"},{9,"IX"},{10,"X"},{40,"XL"},{50,"L"}, {90,"XC"},{100,"C"},{400,"CD"},{500,"D"},{900,"CM"}, {1000,"M"} };
		map<int, string>::reverse_iterator  r_iter;

		string ret;

		r_iter = mapRom.rbegin();
		while (r_iter != mapRom.rend())
		{
			if (num >= r_iter->first)
			{
				ret += r_iter->second;
				num -= r_iter->first;
			}
			else
				r_iter++;
		}
		return ret;
	}

	int romanToInt(string s)
	{
		unordered_map<char, int> mp = \
		{ {'I', 1}, {'V', 5}, { 'X', 10 }, { 'L', 50 }, { 'C', 100 }, { 'D', 500 }, { 'M',1000 }};

		int pos = 0, neg = 0;
		for (unsigned int i = 0; i < s.size() - 1; ++i)
		{
			if (mp[s[i]] < mp[s[i + 1]])
				neg -= mp[s[i]];
			else
				pos += mp[s[i]];
		}
		pos += mp[s.back()];
		return neg + pos;

	}

};

int main()
{
	Solution s;
	string sRet = s.intToRoman(3454);
	cout << sRet << endl;
	cout << s.romanToInt(sRet) << endl;
	return 0;

}