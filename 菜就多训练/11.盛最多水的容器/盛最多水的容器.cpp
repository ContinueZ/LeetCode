#include<vector>
#include<iostream>
using namespace std;

class Solution {
public:
	int maxArea(vector<int>& height) {
		int maxArea = 0;
		for (int i = 0; i < height.size() - 1; ++i)
		{
			for (int j = i + 1; j < height.size(); ++j)
			{
				int tHeight = height[i] > height[j] ? height[j] : height[i];
				maxArea = maxArea > ((j - i)*tHeight) ? maxArea : ((j - i)*tHeight);
			}
		}
		return maxArea;
	}
};

int main()
{
	Solution s;
	vector<int> h = { 1,8,6,2,5,4,8,3,7 };
	int maxArea = s.maxArea(h);
	cout << maxArea << endl;
}