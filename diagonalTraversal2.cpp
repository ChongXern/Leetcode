#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
using namespace std;

class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& nums) {
        unordered_map<int, vector<int>> u_map;
        int max = 1;
        for (int i = 0; i < nums.size(); i++) {
            for (int j = 0; j < nums[i].size(); j++) {
                int f = i + j;
                u_map[f].push_back(nums[i][j]);
                if (f > max) max = f;
            }
        }
        vector<int> diagonal;
        for (int i = 0; i <= max; i++) {
            cout << i << ": ";
            for (int j = u_map[i].size() - 1; j >= 0; j--) {
                cout << u_map[i][j] << ' ';
                diagonal.push_back(u_map[i][j]);
            }
            cout << endl;
        }
        return diagonal;
    }
};

int main() {
    int height;
    cout << "Height: ";
    cin >> height;
    vector<vector<int>> nums(height, vector<int>());
    cout << "Input nums:" << endl;
    for (int i = 0; i < height; i++) {
        int num;
        while (cin >> num && num != -1) {
            nums[i].push_back(num);
        }
    }
    Solution sol;
    vector<int> diag = sol.findDiagonalOrder(nums);
    for (int num : diag) {
        cout << num << ' ';
    }
    cout << endl;
}