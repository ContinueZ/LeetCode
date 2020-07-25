/********************************************************************************
����һ���������� nums?��һ��Ŀ��ֵ target�������ڸ��������ҳ���ΪĿ��ֵ��������������
���������ǵ������±ꡣ����Լ���ÿ������ֻ���Ӧһ���𰸡����ǣ��㲻���ظ��������������ͬ����Ԫ�ء�

ʾ�� :
���� nums = [2, 7, 11, 15], target = 9
��Ϊ nums[0] + nums[1] = 2 + 7 = 9
���Է���[0, 1]
*****************************************************************************************/

#include<iostream>
#include<vector>
#include<map>
using namespace std;

class Solution {
public:
	vector<int> twoSum(vector<int>& nums, int target)
	{
		//��������
		//vector<int> vRet;
		/*for (int i = 0; i < nums.size(); i++)
		{
			for (int j = i + 1; j < nums.size(); j++)
			{
				if (nums[i] + nums[j] == target)
				{
					vRet.push_back(i);
					vRet.push_back(j);
					return vRet;
				}
			}
		}*/

		//ʹ��hash�Ż���
		map<int, int> a;//�ṩһ��һ��hash
		vector<int> b(2, -1);//�������ؽ������ʼ��һ����СΪ2��ֵΪ-1������b
		for (int i = 0; i < nums.size(); i++)
		{
			if (a.count(target - nums[i]) > 0)
			{
				b[0] = a[target - nums[i]];
				b[1] = i;
				break;
			}
			a[nums[i]] = i;//����������map�У�������ȡ����±�
		}
		return b;
	}
};

int main()
{
	vector<int> nums{2,7,11,15};
	int target = 18;
	Solution s;

	vector<int> ret = s.twoSum(nums, target);

	//��ӡ���
	cout << "[" << ret[0] << "," << ret[1] << "]" << endl;

	return 0;

}