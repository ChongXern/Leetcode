// Not a Leetcode question
#include <iostream>
#include <vector>
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

TreeNode* buildTree(vector<string>& nodes, int& index) {
    cout << nodes.size();
    if (index >= nodes.size() || nodes[index] == "null") {
        index++;
        return nullptr;
    }
    int currNode = stoi(nodes[index]);
    TreeNode* root = new TreeNode(currNode);
    index++;
    root->left = buildTree(nodes, index);
    root->right = buildTree(nodes, index);
    return root;
}

int main() {
    vector<string> nodes;
    string node;
    cout << "Input binary tree:" << endl;
    while (cin >> node && node != "end") {
        nodes.push_back(node);
    }
    int index = 0;
    TreeNode* root = buildTree(nodes, index);
    queue<TreeNode*> nodeQueue;
    nodeQueue.push(root);
    cout << endl << "Binary tree:" << endl;
    while (!nodeQueue.empty()) {
        TreeNode* currNode = nodeQueue.front();
        if (currNode) {
            cout << currNode->val << " ";
            if (currNode->right) {
                nodeQueue.push(currNode->right);
            }
            if (currNode->left) {
                nodeQueue.push(currNode->left);
            }
        } else {
            cout << "NULL" << " ";
        }
        nodeQueue.pop();
    }
}