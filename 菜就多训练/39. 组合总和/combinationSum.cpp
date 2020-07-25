//����һ�����ظ�Ԫ�ص�����?candidates?��һ��Ŀ����?target?��
//�ҳ�?candidates?�����п���ʹ���ֺ�Ϊ?target?����ϡ�
//
//candidates?�е����ֿ����������ظ���ѡȡ��
//
//˵����
//
//�������֣�����?target��������������
//�⼯���ܰ����ظ�����ϡ�?
#include<vector>
#include<algorithm>
using namespace std;
class Solution {
private:
	vector<vector<int>> res;
	vector<int> path;
	vector<int> candidates;
public:
	vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
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
		for (int i = start; i < candidates.size()&&target-candidates[i]>=0; ++i) {
			path.push_back(candidates[i]);
			DFS(i, target - candidates[i]);
			path.pop_back();
		}
	}
};