/**
 * https://leetcode.com/problems/simplify-path/
 * String, stack
 * Medium
*/
#include <iostream>
#include <string>
#include <stack>
using namespace std;

class Solution {
public:
    string simplifyPath(string path) {
        stack<string> files;
        for (int i = 1; i < path.size(); i++) {
            string currFile = "";
            if (path[i] == '/') {
                continue;
            } 
            for ( ;i < path.size() && path[i] != '/'; i++) {
                currFile += path[i];
            }
            if (currFile == ".") {
                continue;
            }
            if (currFile == "..") {
                if (!files.empty()) {
                    files.pop();
                }
            } else {
                files.push(currFile);
            }
        }
        string output = "";
        while (!files.empty()) {
            output = "/" + files.top() + output;
            files.pop();
        }
        if (output == "") {
            return "/";
        }
        return output;
    }
};

int main() {
    string path;
    cout << "Input original path: ";
    cin >> path;
    Solution solution;
    string canonicalPath = solution.simplifyPath(path);
    cout << "Canonical path: " << canonicalPath << endl;
}