#include<string>
#include<iostream>
using namespace std;

class Solution {
public:
	int strStr(string haystack, string needle) {
		int position = -1;
		if (haystack.size())
		{
			if (needle.size())
				position = haystack.find(needle);
			else
				return 0;
		}
		else {
			if (needle.size())
				return -1;
			else
				return 0;
		}
		return position;

	}
};

int main()
{
	Solution s;

	int position = s.strStr("hello", "ll");
	cout << position << endl;

	return 0;
}