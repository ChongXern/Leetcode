/**
 * https://leetcode.com/problems/path-sum-ii/
 * Backtracking, Tree, DFS, Binary Tree
 * Medium
*/

#include <iostream>
#include <vector>
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
    void computeSum(TreeNode* root, int target, int& curr, vector<vector<int>>& paths, vector<int>& path) {
        if (!root) {
            return;
        }
        if (curr > target) {
            paths.pop_back();
            return;
        }
        curr += root->val;
        cout << "Current sum at root val " << root->val << ": " << curr << endl;
        path.push_back(root->val);
        if (root->left) {
            // cout << "left: " << root->left->val << endl;
            computeSum(root->left, target, curr, paths, path);
        }
        if (root->right) {
            // cout << "right: " << root->right->val << endl;
            computeSum(root->right, target, curr, paths, path);
        }
        if (!root->left && !root->right && curr == target) {
            paths.push_back(path);
        }
        curr -= root->val;
        path.pop_back();
        return;
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        int curr = 0;
        vector<int> path;
        vector<vector<int>> paths;
        computeSum(root, targetSum, curr, paths, path);
        return paths;
    }
};

int main() {
    TreeNode* root = new TreeNode(5);
    root->left = new TreeNode(4);
    root->right = new TreeNode(8);
    root->left->left = new TreeNode(11);
    root->left->left->left = new TreeNode(7);
    root->left->left->right = new TreeNode(2);
    root->right->left = new TreeNode(13);
    root->right->right = new TreeNode(4);
    root->right->right->left = new TreeNode(5);
    root->right->right->right = new TreeNode(1);
    int targetSum = 22;
    Solution solution;
    vector<vector<int>> paths = solution.pathSum(root, targetSum);
    for (auto path : paths) {
        for (int elem : path) {
            cout << elem << ' ';
        }
        cout << endl;
    }
}