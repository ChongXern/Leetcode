/**
 * https://leetcode.com/problems/valid-parentheses/
 * String, stack
*/
#include <iostream>
#include <string>
#include <stack>
using namespace std;

// try using unordered map next time

class Solution {
public:
    bool isValid(string s) {
        if (s.size() == 1 || s[0] == ')' || s[0] == ']' || s[0] == '}') {
            return false;
        }
        stack<char> brackets;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '(' || s[i] == '[' || s[i] == '{') {
                brackets.push(s[i]);
            } 
            else if (s[i] == ')' && !brackets.empty() && brackets.top() == '(') {
                brackets.pop();
            }
            else if (s[i] == ']' && !brackets.empty() && brackets.top() == '[') {
                brackets.pop();
            }
            else if (s[i] == '}' && !brackets.empty() && brackets.top() == '{') {
                brackets.pop();
            } else {
                return false;
            }
        }
        return brackets.empty();
    }
};

int main() {
    string parenthesis;
    cout << "Input parenthesis:" << endl;
    cin >> parenthesis;
    Solution solution;
    if (solution.isValid(parenthesis)) {
        cout << "valid parenthesis" << endl;
    } else {
        cout << "invalid parenthesis" << endl;
    }
}