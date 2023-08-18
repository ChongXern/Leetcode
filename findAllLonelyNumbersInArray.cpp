// https://leetcode.com/problems/find-all-lonely-numbers-in-the-array/
#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<int> findLonely(vector<int>& nums) {
        int size = nums.size();
        vector<int> lonely_numbers;
        unordered_map<int, int> frequency_map;
        for (int num : nums) {
            frequency_map[num]++;
        }
        for (int num : nums) {
            if (frequency_map[num] == 1 && frequency_map.count(num - 1) == 0 && frequency_map.count(num + 1) == 0) {
                lonely_numbers.push_back(num);
            }
        }
        return lonely_numbers;
    }
};

int main() {
    Solution solution;
    vector<int> nums;
    int num;
    cout << "Input numbers:\n";
    while (cin >> num && num != -1) {
        nums.push_back(num);
    }
    vector<int> lonelyNumbers = solution.findLonely(nums);
    for (int lonelyNum : lonelyNumbers) {
        cout << lonelyNum << ' ';
    }
}