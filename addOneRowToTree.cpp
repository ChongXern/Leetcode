/**
 * https://leetcode.com/problems/add-one-row-to-tree
 * Tree, DFS, BFS, Binary Tree
 * Medium
*/

#include <iostream>
#include <queue>
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
		TreeNode* addOneRow(TreeNode* root, int val, int depth) {
			if (depth == 1) {
				TreeNode* newHead = new TreeNode;
				newHead->val = val;
				newHead->left = root;
				return newHead;
			}
			queue<TreeNode*> depthQueue;
			depthQueue.push(root);
			int queueLen = 1;
			int currDepth = 1;
			while (currDepth < depth - 1) {
				TreeNode* currNode = depthQueue.front();
				if (currNode->left) {
					depthQueue.push(currNode->left);
				}
				if (currNode->right) {
					depthQueue.push(currNode->right);
				}
				queueLen--;
				depthQueue.pop();
				if (!queueLen) {
					queueLen = depthQueue.size();
					currDepth++;
				}
			}
			while (!depthQueue.empty()) {
				TreeNode* currFront = depthQueue.front();
				TreeNode* newLeft = new TreeNode;
				newLeft->val = val;
				newLeft->left = currFront->left;
				TreeNode* newRight = new TreeNode;
				newRight->val = val;
				newRight->right = currFront->right;
				currFront->left = newLeft;
				currFront->right = newRight;
				depthQueue.pop();
			}
			return root;
		}
};

int main() {
    
}
