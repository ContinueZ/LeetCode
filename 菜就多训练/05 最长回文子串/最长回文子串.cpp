#include<iostream>
#include<string>
using namespace std;

class Solution {
public:
	string longestPalindrome(string s) {

		if (s.length() == 1)
			return s;

		string rev = s;//�������s�ķ�ת�ַ���
		string temp;//������ʱ��Ż����ַ���
		reverse(rev.begin(), rev.end());
		if (s == rev) return s;

		string q;//���������ַ���
		int len = 0;//��Ż����ַ����ĳ���

		for (int i = 0; i < s.length(); i++)
		{
			for (int j = i; j < s.length(); j++)
			{
				temp += s[j];
				if (len >= temp.length())
					continue;
				else if (rev.find(temp) != -1)
				{
					string p = temp;
					reverse(p.begin(), p.end());
					if (p == temp)
					{
						len = temp.length();
						q = temp;
					}
				}
				else
					break;

			}
			temp = "";
		}
		return q;
	}
};

int main()
{
	Solution s;
	string str("aacdefcaa");
	string ret = s.longestPalindrome(str);
	cout << ret << endl;

	return 0;
}