#include<iostream>
#include<vector>
#include <iomanip>

using namespace std;

class Solution {
public:
	double findKth(const vector<int> v1, int m, const vector<int> v2, int n, int k)
	{
		if (m > n)
			return findKth(v2, n, v1, m, k);
		if (m == 0)
			return v2[k - 1];
		if (k == 1)
			return v1[0] < v2[0] ? v1[0] : v2[0];

		int pa = k / 2 < m ? k / 2 : m,
		pb = k - pa;
		if (v1[pa - 1] < v2[pb - 1])
		{
			vector<int> va(v1.begin() + pa,v1.end());
			return findKth(va, m - pa, v2, n, k - pa);
		}
			
		else if (v1[pa - 1] > v2[pb - 1])
		{
			vector<int> vb(v2.begin() + pb,v2.end());
			return findKth(v1, m, vb, n - pb, k - pb);
		}
		return v1[pa - 1];
	}
	double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
		int total = nums1.size() + nums2.size();
		if (total & 0x1)
		{
			return findKth(nums1, nums1.size(), nums2, nums2.size(), total / 2 + 1);
		}
		else
			return (findKth(nums1, nums1.size(), nums2, nums2.size(), total / 2) +
				findKth(nums1, nums1.size(), nums2, nums2.size(), total / 2 + 1)) / 2;
	}
};

int main()
{
	vector<int> v1 = { 1,3 };
	vector<int> v2 = { 2 };
	Solution s;
	double dRet = s.findMedianSortedArrays(v1, v2);
	cout << setiosflags(ios::fixed) << dRet << endl;

	return 0;
}