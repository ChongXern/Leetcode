/** https://leetcode.com/problems/binary-tree-maximum-path-sum/
 * Dynamic Programming, Tree, DFS, Binary Tree
 * Hard
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
    void dpAugment(TreeNode* root) {
        if (!root) {
            return;
        }
        dpAugment(root->left);
        dpAugment(root->right);
        if (root->left) {
            root->val += root->left->val;
        }
        if (root->right) {
            root->val += root->right->val;
        }
        return;
    }
    void findMax(TreeNode* root, int& currMax) {
        if (root->val > currMax) {
            currMax = root->val;
        }
        if (root->left) {
            findMax(root->left, currMax);
        }
        if (root->right) {
            findMax(root->right, currMax);
        }
        return;
    }
    int maxPathSum(TreeNode* root) {
        dpAugment(root);
        int max = root->val;
        findMax(root, max);
        return max;
    }
};

int main() {
    TreeNode* root = new TreeNode(2);
    root->left = new TreeNode(-1);
    Solution solution;
    int max = solution.maxPathSum(root);
    cout << max << endl; // Should be 2, don't have to travel to the leaf
}