#include<iostream>
#include<map>
//#include<set>
using namespace std;

class Solution {
public:
	Solution(int n = 1):m_count(n) {};
	int lengthOfLongestSubstring(const string s) {

		if (s.size() == 0)
			return 0;

		int iCount = 0;
		map<char,int> st;
		for (int j = 0; s.size() - j > m_count ; j++)
		{
			st.insert(make_pair(s[j], j));
			iCount = 1;
			for (int i = j + 1; i < s.size(); i++)
			{
				if (st.find(s[i]) == st.end())
				{
					st.insert(make_pair(s[i],i));
					iCount++;
				}
				else 
				{
					if (m_count <= iCount)
						m_count = iCount;
					map<char,int>::iterator it = st.find(s[i]);
					j = it->second;
					st.clear();
					break;
				}
			}
			if(m_count <= iCount)
				m_count = iCount;
		}	
		return m_count;
	}
private:
	string m_str;
	int m_count;
};

int main()
{
	string s = "pwwkew";
	//string s1 = " ";
	//cout << s1.size() << endl;
	Solution cs;
	int n = cs.lengthOfLongestSubstring(s);
	cout << n << endl;
	return 0;
}