//����һ������?candidates?��һ��Ŀ����?target?���ҳ�?candidates?�����п���ʹ���ֺ�Ϊ?target?����ϡ�
//
//candidates?�е�ÿ��������ÿ�������ֻ��ʹ��һ�Ρ�
//
//˵����
//
//�������֣�����Ŀ������������������
//�⼯���ܰ����ظ�����ϡ�
#include<vector>
#include<algorithm>
#include<iostream>
using namespace std;
class Solution {
private:
	vector<vector<int>> res;
	vector<int> path;
	vector<int> candidates;
public:
	vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
		sort(candidates.begin(), candidates.end());
		this->candidates = candidates;
		DFS(0, target);

		return res;

	}
	void DFS(int start, int target) {
		if (target == 0) {
			res.push_back(path);
			return;
		}
		for (int i = start; i < int(candidates.size()) && target - candidates[i] >= 0; ++i) {
			if (i>start&&candidates[i] == candidates[i - 1])
				continue;
			path.push_back(candidates[i]);
			DFS(i + 1, target - candidates[i]);
			path.pop_back();
		}
	}
};

int main()
{
	Solution s;
	vector<int> v({ 10,1,2,7,6,1,5 });

	vector<vector<int>> res = s.combinationSum2(v, 8);
	int i = 0, j = 0;
	cout << '[';
	for (i = 0; i < int(res.size()); ++i)
	{
		cout << '[';
		for (j = 0; j < int(res[i].size()) - 1; ++j)
		{
			cout << res[i][j] << ',';
		}
		cout << res[i][j] << ']';
		if (i < int(res.size()) - 1)
			cout << ',';
	}
	cout << ']' << endl;

	return 0;
}