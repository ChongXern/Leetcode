#include <iostream>
#include <queue>
#include <string>

using namespace std;

struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode() : val(0), left(nullptr), right(nullptr) {}
	TreeNode(int n) : val(n), left(nullptr), right(nullptr) {}
	TreeNode(int n, TreeNode* l, TreeNode* r) : val(n), left(l), right(r) {}
};

class Solution {
public:
    bool isIdentical(TreeNode* root, TreeNode* subRoot) {
        if (!root && !subRoot) {
            return true;
        }
        if ((root && !subRoot) || (!root && subRoot)) {
            return false;
        }
        if (root->val != subRoot->val) {
            return false;
        }
        return isIdentical(root->left, subRoot->left) && isIdentical(root->right, subRoot->right);
    }
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if (!root) {
            return false;
        }
        if (isIdentical(root, subRoot)) {
            return true;
        }
        return isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot);
    }
};

TreeNode* buildTree(vector<string>& nodes, int& index) {
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

TreeNode* buildTree(vector<string>& head) {
    int index = 0;
    TreeNode* root = buildTree(head, index);
    return root;
}

void printTree(TreeNode* root) {
    queue<TreeNode*> nodeQueue;
    nodeQueue.push(root);
    cout << endl << "Binary tree:" << endl;
    while (!nodeQueue.empty()) {
        TreeNode* currNode = nodeQueue.front();
        if (currNode) {
            cout << currNode->val << " ";
            if (currNode->left) {
                nodeQueue.push(currNode->left);
            }
            if (currNode->right) {
                nodeQueue.push(currNode->right);
            }
        } else {
            cout << "NULL" << " ";
        }
        nodeQueue.pop();
    }
    cout << endl;
}

int main() {
	TreeNode *root, *subRoot;
    vector<string> rootNodes;
    string rootNode;
    cout << "Input binary tree for root:" << endl;
    while (cin >> rootNode && rootNode != "end") {
        rootNodes.push_back(rootNode);
    }
    root = buildTree(rootNodes);
    printTree(root);
    vector<string> subrootNodes;
    string subrootNode;
    cout << "Input binary tree for sub-root:" << endl;
    while (cin >> subrootNode && subrootNode != "end") {
        subrootNodes.push_back(subrootNode);
    }
    subRoot = buildTree(subrootNodes);
	Solution solution;
	bool isSubtree = solution.isSubtree(root, subRoot);
	if (isSubtree) {
		cout << "is subtree" << endl;
	} else {
		cout << "is not subtree" << endl;
	}
}
