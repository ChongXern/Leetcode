/**
 * https://leetcode.com/problems/permutations
 * Array, Backtracking
 * Medium
 */
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void computeBacktracking(vector<int>& nums, vector<vector<int> >& permutations, int start) {
        if (start == nums.size() - 1) {
            permutations.push_back(nums);
            return;
        }
        for (int i = start; i < nums.size(); i++) {
            swap(nums[i], nums[start]);
            computeBacktracking(nums, permutations, start + 1);
            swap(nums[i], nums[start]);
        }
    }
    vector<vector<int> > permute(vector<int>& nums) {
        vector<vector<int>> permutations;
        computeBacktracking(nums, permutations, 0);
        return permutations;
    }
};

int main() {
   vector<int> nums;
   int num;
   cout << "Input numbers: " << endl;
   while (cin >> num && num != -1) {
	  nums.push_back(num);
   }
   Solution solution;
   vector<vector<int> > permutations = solution.permute(nums);
   cout << endl << "Permutations:" << endl;
   for (auto perms : permutations) {
	  for (auto perm : perms) {
		 cout << perm << ' ';
	  }
	  cout << endl;
   }
}
