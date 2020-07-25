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
			std::cout << it->first << "重复了" << std::endl;
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
	std::cout << "请您初始化一个数组\n";
	std::cout << "请先输入数组的长度len:";
	std::cin >> len;
	std::cout << "您输入的数组长度为:" << len << std::endl;
	std::cout << "现在请您依次输入数组中的元素，注意，元素大小应在0~len-1之间)：";
	for(i = 0; i < len; i++)
	{
		std::cin >> szArray[i];
	}

	std::cout << "您输入的数组为：";
	for (i = 0; i < len - 1; i++)
	{
		std::cout << szArray[i] <<",";
	}
	std::cout << szArray[i] << std::endl;

	Statistics(szArray, len);
	return 0;
}