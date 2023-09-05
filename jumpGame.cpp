#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool canJump(vector<int>& nums) {
        if (nums.size() == 1) {
            return true;
        }
        int start = nums.size() - 2;
        int end = nums.size() - 1;
        bool foundStart;
        while (start >= 0) {
            foundStart = false;
            if (end <= nums[start] + start) {
                foundStart = true;
                end = start;
                start = end - 1;
            } else {
                start--;
            }
        }
        if (foundStart && start == -1) {
            return true;
        }
        return false;
    }
};

int main() {
	vector<int> nums;
	int num;
	while (cin >> num && num != -1) {
		nums.push_back(num);
	}
	Solution solution;
	if (solution.canJump(nums)) {
		cout << "Can jump" << endl;
	} else {
		cout << "Cannot jump" << endl;
	}
}
