#include<iostream>
#include<map>

void Statistics(int sz[], int len)
{
	std::map<int,int> m;
	for (int i = 0; i < len; ++i)
	{
		auto it = m.find(sz[i]);
		if (it != m.end())
		{
			it->second++;
			std::cout << it->first << "�ظ���" << std::endl;
			return;
		}
		else
			m.insert(std::pair<int, int>(sz[i],1));
	}
	for (auto it : m)
	{
		std::cout << it.first << ":" << it.second << std::endl;
	}
}
int main()
{
	int i = 0;
	int len = 0;
	int szArray[10] = { 0 };
	std::cout << "������ʼ��һ������\n";
	std::cout << "������������ĳ���len:";
	std::cin >> len;
	std::cout << "����������鳤��Ϊ:" << len << std::endl;
	std::cout << "���������������������е�Ԫ�أ�ע�⣬Ԫ�ش�СӦ��0~len-1֮��)��";
	for(i = 0; i < len; i++)
	{
		std::cin >> szArray[i];
	}

	std::cout << "�����������Ϊ��";
	for (i = 0; i < len - 1; i++)
	{
		std::cout << szArray[i] <<",";
	}
	std::cout << szArray[i] << std::endl;

	Statistics(szArray, len);
	return 0;
}