#include<vector>
#include<iostream>
#include<map>
#include<unordered_map>
using namespace std;

class Solution {
public:
//	vector<int> findSubstring(string s, vector<string>& words) {
//		if (words.size() == 0) {
//			return {};
//		}
//		vector<int> index;
//		Permutation(words);
//		for (auto str : res) {
//			int pos = 0;
//			while ((pos = s.find(str,pos)) != string::npos &&
//				find(index.begin(), index.end(), pos) == index.end()) {
//					index.push_back(pos);
//				pos++;
//			}
//		}
//		return index;
//	}
//
//
//	void _Permutation(vector<string>& v, vector<string>::iterator&& ibegin)
//	{
//		if (ibegin == v.end())
//		{
//			string str;
//			for (auto s : v) {
//				str += s;
//			}
//			res.push_back(str);
//		}
//		else
//		{
//			for (auto it = ibegin; it != v.end(); ++it)
//			{
//				swap(*it, *ibegin);
//
//				_Permutation(v, ibegin+1);
//
//				swap(*it, *ibegin);
//			}
//		}
//	}
//
//
//	void Permutation(vector<string>& words)
//	{
//		if (words.size() == 0)
//			return;
//
//		_Permutation(words, words.begin());
//	}
//
//private:
//	vector<string> res;

public:
	vector<int> findSubstring(string s, vector<string>& words) {
		if (words.size() == 0)return {};
		unordered_map<string, int> wordcnt;
		for (auto& str : words) {
			wordcnt[str]++;
		}

		int len = words[0].size();

		vector<int> ans;
		for (int i = 0; i < len; ++i) {
			int left = i;
			int right = left;
			int cnt = 0;

			unordered_map<string, int> windows;
			while (left + words.size()*len <= s.size()) {
				string temp = "";
				while (cnt < words.size()) {
					temp = s.substr(right, len);
					if (wordcnt.find(temp) == wordcnt.end() || windows[temp] >= wordcnt[temp])break;
					windows[temp]++;
					++cnt;
					right += len;
				}

				if (windows == wordcnt)
					ans.push_back(left);

				if (wordcnt.find(temp) != wordcnt.end()) {
					windows[s.substr(left, len)]--;
					--cnt;
					left += len;
				}
				else {
					right += len;
					left = right;
					cnt = 0;
					windows.clear();
				}
			}
		}
		return ans;
	}
};

/*---------------------------------leetcode���--------------------------------*/
vector<int> findSubstring(string s, vector<string>& words) {
	if (words.size() == 0) return {};
	unordered_map<string, int> wordcnt;
	//��wordsԪ����ӵ�map�У�secondֵ��Ϊ1
	for (auto& w : words) {
		wordcnt[w]++;
	}
	int len = words[0].size();   //ÿ��words�ĳ���

	vector<int> ans;
	for (int i = 0; i < len; i++) {
		int left = i;
		int right = left;
		int cnt = 0;

		unordered_map<string, int> window;
		while (left + words.size() * len <= s.size()) {
			string temp = "";
			while (cnt < words.size()) {
				temp = s.substr(right, len);
				//��words���Ҳ�����ǰ���ʣ����߻���������õ��ʵĸ���������words��õ��ʵĸ���
				if (wordcnt.find(temp) == wordcnt.end() || window[temp] >= wordcnt[temp]) break;
				window[temp]++;
				cnt++;
				right += len;
			}

			if (window == wordcnt) {
				ans.push_back(left);
			}

			if (wordcnt.find(temp) != wordcnt.end()) {
				window[s.substr(left, len)]--;
				cnt--;
				left += len;
			}//
			else {
				right += len;
				left = right;
				cnt = 0;
				window.clear();
			}//��ǰ���ʲ���words�whileѭ����windows[temp]�����Լӣ���������right+=len
		}
	}
	return ans;
}

int main()
{
	Solution s;
	vector<int> res;
	vector<string> str{ "foo","bar" };
	res = s.findSubstring("foobarfoobar", str);
	for (auto it : res) {
		cout << it << endl;
	}
	return 0;
}