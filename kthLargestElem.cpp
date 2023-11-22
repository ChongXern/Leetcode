/**
 * https://leetcode.com/problems/kth-largest-element-in-an-array/
 * Array, Divide and Conquer, Sorting, Priority queue, Quickselect
 * Medium
 */
#include <iostream>
#include <queue>
using namespace std;

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int> max_heap;
        for (int num : nums) {
            max_heap.push(num);
        }
        for (int i = 0; i < k - 1; i++) {
            max_heap.pop();
        }
        return max_heap.top();
    }
};

int main() {
	vector<int> nums;
	int k, numsSize;
	cout << "Input nums array size: ";
	cin >> numsSize;
	int num;
	cout << "Input array" << endl;
	while (numsSize) {
		cin >> num;
		nums.push_back(num);
		numsSize--;
	}
	cout << "Input K: ";
	cin >> k;
	Solution solution;
	int kthLargest = solution.findKthLargest(nums, k);
	cout << "k-th largest element in array: " << kthLargest << endl;
}
