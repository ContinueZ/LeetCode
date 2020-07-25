#include<iostream>

class Solution {
public:
	bool isPalindrome(int x) {

		long ret = 0;
		int iMid = x;
		int iTmp = 0;

		if (x < 0)
			return false;

		while (iMid)
		{
			iTmp = iMid % 10;
			iMid = iMid / 10;
			ret = 10 * ret + iTmp;
		}
		
		if (ret == x)
			return true;
		else
			return false;
	}
};

int main()
{
	Solution s;
	bool b = s.isPalindrome(121);
	if (b)
		std::cout << "是回文数\n";
	else
		std::cout << "不是回文数\n";

}