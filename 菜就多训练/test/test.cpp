#include<iostream>
#include<vector>
#include<algorithm>
#include<map>
#include<unordered_map>
#include<string>
#include<cassert>
#include <cstring>
#include <cstdio>
#include<iomanip>

using namespace std;

class Solution {
public:
	vector<int> grayCode(int n) {
		int size = (1 << n);//±íÊ¾1×óÒÆnÎ»
		vector<int> result;
		for (int i = 0; i < size; ++i) {
			result.push_back(i ^ (i >> 1));
		}
		return result;
	}
};
int main() 
{
	Solution s;
	int n;
	cin >> n;
	s.grayCode(n);

	return 0;
}