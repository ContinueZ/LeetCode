#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
	int reverse(int x) {
		//int ret = 0;
		//int nSize;
		//vector<int> v;
		//vector<int> vtmp;

		//if (x == 0)
		//	return 0;

		//if (x < 0)
		//{
		//	flag = -1;
		//	x = abs(x);
		//}

		//while (x % 10 == 0)
		//{
		//	x = x / 10;
		//}

		//while (x % 10)
		//{
		//	v.push_back(x % 10);
		//	x = x / 10;
		//}

		//for (vector<int>::iterator it = v.begin(); it != v.end(); it++)
		//{
		//	if (*it > 0)
		//	{
		//		vtmp.assign(it, v.end());
		//		break;
		//	}	
		//}

		//nSize = vtmp.size();
		//for (vector<int>::iterator it = vtmp.begin(); it != vtmp.end(); it++)
		//{		
		//	for (int i = nSize - 1; i > 0; i--)
		//	{
		//		*it *= 10;
		//	}
		//	nSize--;
		//}

		//for (int i = 0; i < vtmp.size(); i++)
		//{
		//	ret += vtmp[i];
		//}

		//if (flag == -1)
		//	ret = 0 - ret;

		//return ret;
		long rev = 0;
		while (x)
		{
			int pop = x % 10;
			x = x / 10;
			rev = rev * 10 + pop;
		}
		return (rev > INT_MAX || rev < INT_MIN) ? 0 : static_cast<int>(rev);
	}
private:
	int flag;
};

int main()
{
	Solution s;
	int ret = s.reverse(-120);
	cout << ret << endl;

	cout << __cplusplus << endl;

	return 0;
}