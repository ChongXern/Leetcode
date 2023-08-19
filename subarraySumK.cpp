/**
 * https://leetcode.com/problems/subarray-sum-equals-k/
 * Array, Hash Table, Prefix Sum
 */
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	bool isSubarraySumK(vector<int>& nums, int k, int start, int end) {
		int sum = 0;
		for (int i = start; i <= end; i++) {
			if (sum >= k) {
				return false;
			}
			sum += nums[i];
		}
		if (sum == k) {
			return true;
		}
		return false;
	}
    int subarraySum(vector<int>& nums, int k) {

    }
};


vector<int> vectorFromArray(int* array, int size) {
}

int main() {
	int numsSize, k;
	cout << "Input size of array: ";
	cin >> numsSize;
	int *nums = new int[numsSize];
	cout << "Input nums:" << endl;
	int num;
	for (int i = 0; i < numsSize; i++) {
		cin >> num;
		nums[i] = num;
	}
}
