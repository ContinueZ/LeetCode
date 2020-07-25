#include<iostream>
#include<vector>
#include<set>
#include<algorithm>
using namespace std;

/*-----------------------------leedcode��ʱ------------------------------*/
class Solution {
public:
	int calculateMinimumHP(vector<vector<int>>& dungeon) {
		size_t m = dungeon.size();
		size_t n = dungeon[0].size();
		if (m == 1 && n == 1)
		{
			if (dungeon[0][0] >= 0)return 1;
			else return 1 - dungeon[0][0];
		}

		string sload;
		for (int i = 0; i < n-1 ; ++i)sload.push_back('r');
		for (int j = 0; j < m-1 ; ++j)sload.push_back('d');
		getAllLoad(sload, 0,sload.size()-1);

		int k = 0, i = 0, j = 0;
		set<int> s;
		int sum = dungeon[0][0];//ÿ��·������֮��
		int iback = dungeon[0][0];//ÿ��·���������ڵ����ֵ
		for (auto it = ans.begin(); it != ans.end(); ++it) {
			while (k < sload.size()) {
				switch ((*it)[k])
				{
				case 'r':
					++j;
					break;
				case 'd':
					++i;
					break;
				}
				sum += dungeon[i][j];
				if (sum < iback)iback = sum;
				++k;
			}
			s.insert(iback);
			iback = dungeon[0][0];
			sum = dungeon[0][0];
			k = 0;
			i = 0;
			j = 0;
		}
		
		if (*s.rbegin() >= 0)return 1;
		else return 1-*s.rbegin();
	}

	void getAllLoad(string& s,int start,int end) {
		if (start == end)
		{
			if(find(ans.begin(),ans.end(),s)==ans.end())
				ans.push_back(s);
		}
		else
		{
			for (int i = start; i <= end; ++i)
			{
				Swap(s, start, i);
				getAllLoad(s, start+1,end);
				Swap(s,start,i);
			}
		}
	}

	void Swap(string& str, int i, int j) {
		char temp = str[i];
		str[i] = str[j];
		str[j] = temp;
	};
private:
	vector<string> ans;
};

/*---------------------------------leetcodeͨ��--------------------------------*/
class Solution {
public:
	int calculateMinimumHP(vector<vector<int>>& dungeon) {
		int n = dungeon.size(), m = dungeon[0].size();
		//����һ��(n+1)*��m+1���ľ��󣬳�ֵ��ΪINT_MAX
		vector<vector<int>> dp(n + 1, vector<int>(m + 1, INT_MAX));
		dp[n][m - 1] = dp[n - 1][m] = 1;//�ػ�������ֵ
		for (int i = n - 1; i >= 0; --i)
			for (int j = m - 1; j >= 0; --j) {
				//�õ����������У���С��dp����ǰλ�õ�ֵ�������1����󣬾͵õ��õ�dp
				dp[i][j] = max(min(dp[i + 1][j], dp[i][j + 1]) - dungeon[i][j], 1);
			}
		return dp[0][0];
	}
};


int main()
{
	Solution s;
	vector<vector<int>> v{ 
	{-2 , -3,  3 },
	{-5 , -10,	1},
	{10	, 30,  -5} };

	int ret = s.calculateMinimumHP(v);
	cout << ret << endl;

	return 0;
}