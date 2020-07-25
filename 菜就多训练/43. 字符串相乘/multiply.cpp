#include<iostream>
#include<string>
#include<vector>
using namespace std;

class Solution {
public:
	string multiply(string num1, string num2) {
		string ans;
		vector<int> a, b, c;
		c.resize(num1.size() + num2.size() - 1);
		//�����ַ�������
		for (int i = num1.size() - 1; i >= 0; --i)a.push_back(num1[i]-'0');
		for (int j = num2.size() - 1; j >= 0; --j)b.push_back(num2[j]-'0');

		
		for (int i = 0; i < a.size(); ++i) {
			for (int j = 0; j < b.size(); ++j) {
				c[i + j] += a[i] * b[j];//ʹ��+=��ʾ�����ж��ֵ�洢�ڸ�λ��
			}
		}

		//������
		int k = 0;
		for (int i = 0; i < c.size(); ++i) {
			k += c[i];
			char c = k % 10 + '0';
			ans = c + ans;
			k /= 10;
		}

		//���н�λ
		while (k) {
			char c = k % 10 + '0';
			ans = c + ans;
			k /= 10;
		}

		//�𰸳��ȴ���1�����ǵ�һλΪ0,ɾ��ans
		if (ans.size() > 1 && ans[0] == '0')ans.erase(ans.begin());
		return ans;
	}
};

int main()
{
	string s1 = "123";
	string s2 = "456";
	Solution s;
	string ans = s.multiply(s1, s2);
	cout << ans << endl;

	return 0;
}