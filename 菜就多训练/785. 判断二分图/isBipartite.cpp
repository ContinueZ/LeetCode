#include<iostream>
#include<vector>
#include<queue>
using namespace std;

class Solution {
private:
	static constexpr int UNCOLORED = 0;
	static constexpr int RED = 1;
	static constexpr int GREEN = 2;
	bool valid;
	vector<int> color;
public:
	//-----------------------------�������------------------------------
	//void dfs(int node, int c, vector<vector<int>>& graph) {
	//	color[node] = c;
	//	int cNei = (color[node] == RED ? GREEN : RED);
	//	//graph[node]��ʾ��node�ڵ����ڵ����нڵ㣬graph[node] �в�����node������graph[node]��û���ظ���ֵ��
	//	for (int neighbor : graph[node]) {
	//		if (color[neighbor] == UNCOLORED) {
	//			dfs(neighbor, cNei, graph);
	//			if (!valid)
	//				return;
	//		}
	//		else if (color[neighbor]!=cNei) {
	//			valid = false;
	//			return;
	//		}
	//	}
	//}
	//bool isBipartite(vector<vector<int>>& graph) {
	//	int n = graph.size();
	//	valid = true;
	//	color.assign(n, UNCOLORED);

	//	for (int i = 0; i < n&&valid; ++i) {
	//		if(color[i] == UNCOLORED)
	//			dfs(i, RED, graph);
	//	}
	//	return valid;
	//}

	//-----------------------------�������------------------------------
	bool isBipartite(vector<vector<int>>& graph) {
		int n = graph.size();
		valid = true;
		color.assign(n, UNCOLORED);

		for (int i = 0; i < n; ++i) {
			if (color[i] == UNCOLORED) {

				queue<int> q;//������ȣ�����ʵ��
				q.push(i);
				color[i] = RED;

				while (!q.empty()) {
					int node = q.front();
					q.pop();
					for (int neighbor : graph[node]) {
						int cNei = (color[node] == RED ? GREEN : RED);
						if (color[neighbor] == color[node]) {
							valid = false;
							return valid;
						}//��ɫ��ͬ������false
						else if (color[neighbor] == UNCOLORED) {
							q.push(neighbor);
							color[neighbor] = cNei;
						}//û�б������Ķ�������		
					}
				}	
			}
		}

		return valid;
	}
};

int main()
{
	vector<vector<int>> v{{1, 3}, { 0, 2}, { 1, 3}, { 0, 2 }};

	Solution s;
	bool bRet = s.isBipartite(v);
	cout << bRet << endl;

	return 0;

}