/**
 * https://leetcode.com/problems/combinations/
 * Backtracking
 * Medium
*/
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void backtrack(vector<vector<int> >& combinations, vector<int>& currentCombo, int start, int k, int n){
        if (k == 0) {
            combinations.push_back(currentCombo);
            return;
        }
        for (int i = start; i <= n; i++) {
            currentCombo.push_back(i);
            backtrack(combinations, currentCombo, i + 1, k - 1, n);
            currentCombo.pop_back();
        }
    }
    vector<vector<int> > combine(int n, int k) {
        vector<vector<int> > combinations;
        vector<int> currentCombination;
        backtrack(combinations, currentCombination, 1, k, n);
        return combinations;
    }
};

int main() {
    int n, k;
    cout << "Input n and k:\n";
    cin >> n >> k;
    Solution solution;
    vector<vector<int> > combinations = solution.combine(n, k);
    cout << "Combinations:\n";
    for (int i = 0; i < combinations.size(); i++) {
        for (int j = 0; j < k; j++) {
            cout << combinations[i][j] << ' ';
        }
        cout << endl;
    }
}