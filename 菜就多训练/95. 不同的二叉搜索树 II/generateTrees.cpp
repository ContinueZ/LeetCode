#include "..\..\include.h"

//Definition for a binary tree node.
 struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode() : val(0), left(nullptr), right(nullptr) {}
     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 };
 
class Solution {
public:
	vector<TreeNode*> generateTrees(int n) {	

		if (!n)return{};
		return generateTreesHelp(1, n);
	}
	vector<TreeNode*> generateTreesHelp(int l, int r) {

		if (l > r) return { nullptr };

		vector<TreeNode*> allTrees;

		for (int i = l; i <= r; ++i) {
			vector<TreeNode*> leftTrees = generateTreesHelp(l, i - 1);
			vector<TreeNode*> rightTrees = generateTreesHelp(i + 1, r);
			for (auto& left : leftTrees) {
				for (auto& right : rightTrees) {
					TreeNode* currTree = new TreeNode(i);
					currTree->left = left;
					currTree->right = right;
					allTrees.emplace_back(currTree);
				}
			}
		}
		return allTrees;
	}
};

int main()
{
	int n = 3;
	Solution s;
	vector<TreeNode*> v = s.generateTrees(n);

	return 0;
}