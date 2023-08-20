/**
 * https://leetcode.com/problems/find-peak-element/
 * Array, Binary Search
 * Medium
 */
// #include "functions.h"
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int binarySearch(vector<int>& nums, int left, int right) {
        if (left > right) {
            return -1;
        }
        int mid = left + (right - left) / 2;
        if ((mid == 0 || nums[mid - 1] < nums[mid]) && (mid == nums.size() - 1 || nums[mid] > nums[mid + 1])) {
            return mid; 
        }
        int leftPeak = binarySearch(nums, left, mid - 1);
        int rightPeak = binarySearch(nums, mid + 1, right);
        if (leftPeak != -1) {
            return leftPeak;
        } else {
            return rightPeak;
        }
    }
    int findPeakElement(vector<int>& nums) {
        return binarySearch(nums, 0, nums.size() - 1);
    }
};

vector<int> vectorFromArray(int* array, int len) {
   vector<int> vector;
   for (int i = 0; i < len; i++) {
	  vector.push_back(array[i]);
   }
   return vector;
}

int main() {
   int numsSize;
   cout << "Input size of array: ";
   cin >> numsSize;
   int *nums = new int[numsSize];
   int num;
   for (int i = 0; i < numsSize; i++) {
	  cin >> num;
	  nums[i] = num;
   }
   Solution solution;
   vector<int> numsVect = vectorFromArray(nums, numsSize);
   int peak = solution.findPeakElement(numsVect);
   cout << "Peak element: " << peak  << endl;
}
