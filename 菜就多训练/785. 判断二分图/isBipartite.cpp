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
	//-----------------------------深度优先------------------------------
	//void dfs(int node, int c, vector<vector<int>>& graph) {
	//	color[node] = c;
	//	int cNei = (color[node] == RED ? GREEN : RED);
	//	//graph[node]表示与node节点相邻的所有节点，graph[node] 中不存在node，并且graph[node]中没有重复的值。
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

	//-----------------------------广度优先------------------------------
	bool isBipartite(vector<vector<int>>& graph) {
		int n = graph.size();
		valid = true;
		color.assign(n, UNCOLORED);

		for (int i = 0; i < n; ++i) {
			if (color[i] == UNCOLORED) {

				queue<int> q;//广度优先，队列实现
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
						}//颜色相同，返回false
						else if (color[neighbor] == UNCOLORED) {
							q.push(neighbor);
							color[neighbor] = cNei;
						}//没有遍历过的都进队列		
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