#include<iostream>
#include<string>
using namespace std;

class Solution {
public:
	int myAtoi(string str) {
		long long rev = 0;
		int len = 0;    //记录字符串长度
		int temp = 0;    //记录+-出现的次数
		int flag = 0;    //出现-  置1

		for (auto c : str)
		{
			if (c == ' '&&temp == 0 && len == 0)
				continue;
			else if ((c == '-' || c == '+') && len == 0)
			{
				temp++;
				if (c == '-')
					flag = 1;
			}
			else if (c - '0' >= 0 && c - '0' <= 9 && temp < 2)
			{
				rev = rev * 10 + (c - '0');
				len++;
				if (rev - 1 > INT_MAX)
					break;
			}
			else
				break;

		}
		if (flag == 1)
			return -rev < INT_MIN ? INT_MIN : -rev;

		return rev > INT_MAX ? INT_MAX : rev;
	}
};

int main()
{
	Solution s;
	int rev;
	string str(" 02432");
	rev = s.myAtoi(str);
	cout << rev << endl;

	return 0;
}