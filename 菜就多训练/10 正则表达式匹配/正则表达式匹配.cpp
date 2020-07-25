#include<iostream>
#include<string>

class Solution {
public:
	bool isMatch(std::string s, std::string p) {
		if (p.empty())
			return s.empty();

		bool first_match = (s[0] == p[0]) || (p[0] == '.');

		if (p.size() >= 2 && p[1] == '*')
		{
			if (s.empty())
				//sΪ�գ�p�е�ǰ*ƥ��ǰһ���ַ�0�Σ�Ȼ������*,������ַ���s����ƥ��
				return isMatch(s, p.substr(2));
			else
				//���ͣ�����������ַ��� '*' ��ϣ�
				//����ƥ����ַ� 0 �Σ�Ȼ���������ַ��� '*'
				//���ߵ� p[0] �� s[0] ƥ����ƶ� s
				return isMatch(s, p.substr(2)) || (first_match && isMatch(s.substr(1), p));

		}
		else
		{
			if (s.empty())
				return false;
			else
			{
				return first_match && isMatch(s.substr(1), p.substr(1));
			}
		}

	}
};

int main()
{
	Solution s;
	bool b = s.isMatch("mississippi", "mis*is*p*.");
	if (b)
		std::cout << "ƥ��\n";
	else
		std::cout << "��ƥ��\n";

	return 0;
}