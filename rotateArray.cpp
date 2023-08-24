/**
 * https://leetcode.com/problems/rotate-array/description/
 * Array, Math, Two Pointers
 * Medium
 */
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// Queue Approach

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        queue<int> numsQueue;
        for (int i = nums.size() - 1; i >= 0; i--) {
            numsQueue.push(nums[i]);
        }
        for (int i = 0; i < k; i++) {
            numsQueue.push(numsQueue.front());
            numsQueue.pop();
        }
        int i = nums.size() - 1;
        while (!numsQueue.empty()) {
            nums[i] = numsQueue.front();
            numsQueue.pop();
            i--;
        }
    }
};

vector<int> vectorFromArray(int* array, int size) {
	vector<int> vector;
	for (int i = 0; i < size; i++) {
		vector.push_back(array[i]);
	}
	return vector;
}

int main() {
	int size;
	cout << "Input size: ";
	cin >> size;
	int* numsArr = new int[size];
	cout << "Input array:" << endl;
	int num;
	for (int i = 0; i < size; i++) {
		cin >> num;
		numsArr[i] = num;
	}
	vector<int> nums = vectorFromArray(numsArr, size);
	delete [] numsArr;
	int k;
	cout << "Input k: ";
	cin >> k;
	Solution solution;
	solution.rotate(nums, k);
	for (int i = 0; i < size; i++) {
		cout << nums[i] << ' ';
	}
	cout << endl;
}
