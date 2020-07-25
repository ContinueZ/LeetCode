#include<vector>
#include<algorithm>
#include<iostream>

using namespace std;
class Solution {
public:
	int removeElement(vector<int>& nums, int val) {
		sort(nums.begin(), nums.end());
		auto iter = nums.begin();
		for (; iter != nums.end(); ++iter)
		{
			if (*iter == val)
			{
				auto itend = iter;
				while (itend != nums.end()&&*itend == val)
				{ 
					itend++; 
				}
				nums.erase(iter,itend);	
				//--iter;
				return nums.size();
			}
				
		}
		return nums.size();
	}
};

int main()
{
	Solution s;
	vector<int> v = { 0,1,2,2,3,0,4,2 };
	int length = s.removeElement(v,2);

	cout << length << endl;

	return 0;
}