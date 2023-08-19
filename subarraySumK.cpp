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
	    int count = 0;
	    int start = 0;
	    int end = 1;
	    currSum = nums[0];
	    while (start < nums.size() - 1 && end < nums.size() - 1) {
		    cout << currSum << endl;
		    if (currSum == k) {
			    count++;
			    currSum -= nums[start];
			    start++;
			    end++;
			    currSum += nums[end];
		    } 
		    else if (currSum < k) {
			    end++;
			    currSum += nums[end];
		    } else {
			    currSum -= nums[start];
			    start++;
		    }
	    }
	    return count;
    }
};


vector<int> vectorFromArray(int* array, int size) {
	vector<int> vector;
	for (int i = 0; i < size; i++) {
		vector.push_back(array[i];
	}
	return vector;
}

int main() {
	int numsSize, k;
	cout << "Input size of array: ";
	cin >> numsSize;
	int *numsArr = new int[numsSize];
	cout << "Input nums:" << endl;
	int num;
	for (int i = 0; i < numsSize; i++) {
		cin >> num;
		numsArr[i] = num;
	}
	cout << "Input k: ";
	cin >> k;
	vector<int> nums = vectorFromArray(numsArr, numsSize);
	Solution solution;
	int output = solution.subarraySum(nums, k);
	cout << "Total number of subarrays whose sum equals to k: " << output << endl;
}
