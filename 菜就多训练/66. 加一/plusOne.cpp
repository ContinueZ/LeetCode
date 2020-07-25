//给定一个由整数组成的非空数组所表示的非负整数，在该数的基础上加一。
//
//最高位数字存放在数组的首位， 数组中每个元素只存储单个数字。
//
//你可以假设除了整数 0 之外，这个整数不会以零开头。


#include<vector>
using namespace std;
class Solution {
public:
	vector<int> plusOne(vector<int>& digits) {
		int n = int(digits.size());
		if (digits[--n] == 9)
		{
			while (n >= 0)
			{
				if (digits[n] == 9) {
					digits[n] = 0;
					--n;
				}
				else {
					digits[n]++;
					return digits;
				}

			}
			vector<int> vres;
			vres.insert(vres.begin(), 1);
			vres.insert(vres.end(), digits.begin(), digits.end());
			return vres;
		}
		else {
			digits[n]++;
			return digits;
		}
	}
};