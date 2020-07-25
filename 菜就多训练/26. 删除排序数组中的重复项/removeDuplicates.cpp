#include<vector>
#include<iostream>
#include<algorithm>
using namespace std;


class Solution {
public:
	int removeDuplicates(vector<int>& nums) {
		
		int size = int(nums.size());
		if (size == 0)
			return 0;
		if (size == 1)
			return 1;
		for (int i = 0; i<size; ++i)
		{
			int icom = nums[i];
			int iwork = i;
			int icopy = i;
			int icount = 0;
			while (iwork+1 < size&&nums[iwork + 1] == icom) 
			{ 
				iwork++; 
				icount++; 
			}
			if (iwork - icopy > 0)
			{
				while (iwork < size-1)
				{
					nums[++icopy] = nums[++iwork];
				}
				size -= icount;
				icount = 0;
			}
			
		}
		return size;
	}
};

//C++·ºĞÍËã·¨
class Solution1 {
public:
	int removeDuplicates(vector<int>& nums) {
		auto iter = unique(nums.begin(), nums.end());      //ÖØÅÅÈİÆ÷
		nums.erase(iter, nums.end());    //É¾³ıÖØ¸´ÔªËØ
		return nums.size();
	}
};
int main()
{
	Solution1 s;
	vector<int> v = { 1,1,2 };
	int length = s.removeDuplicates(v);

	cout << length << endl;

	return 0;
}