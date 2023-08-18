/**
 * https://leetcode.com/problems/cousins-in-binary-tree/
 * Tree, DFS, BFS, Binary Tree
 * Easy
 */
#include <iostream>
using namespace std;

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
		pair<int, TreeNode*> findDepthAndParent(TreeNode* root, int target, int depth, TreeNode* parent) {
			if (!root) {
				return make_pair(-1, nullptr);
			}
			if (root->val == target) {
				return make_pair(depth, parent);
			}
			auto leftResult = findDepthAndParent(root->left, target, depth + 1, root);
			if (leftResult.first != -1) {
				return leftResult;
			}
			return findDepthAndParent(root->right, target, depth + 1, root);
		}
		bool isCousins(TreeNode* root, int x, int y) {
			auto xInfo = findDepthAndParent(root, x, 0, nullptr);
			auto yInfo = findDepthAndParent(root, y, 0, nullptr);
			return (xInfo.first == yInfo.first) && (xInfo.second != yInfo.second);
		}
};

int main() {
	TreeNode* root;
	int x, y;
	cout << "Input both nodes: ";
	cin >> x >> y;
	Solution solution;
	if (solution.isCousins(root, x, y)) {
		cout << "cousins" << endl;
	} else {
		cout << "not cousins" << endl;
	}
}
