//����һ����������ɵķǿ���������ʾ�ķǸ��������ڸ����Ļ����ϼ�һ��
//
//���λ���ִ�����������λ�� ������ÿ��Ԫ��ֻ�洢�������֡�
//
//����Լ���������� 0 ֮�⣬��������������㿪ͷ��


#include<vector>
using namespace std;
class Solution {
public:
	vector<int> plusOne(vector<int>& digits) {
		int n = int(digits.size());
		if (digits[--n] == 9)
		{
			while (n >= 0)
			{
				if (digits[n] == 9) {
					digits[n] = 0;
					--n;
				}
				else {
					digits[n]++;
					return digits;
				}

			}
			vector<int> vres;
			vres.insert(vres.begin(), 1);
			vres.insert(vres.end(), digits.begin(), digits.end());
			return vres;
		}
		else {
			digits[n]++;
			return digits;
		}
	}
};