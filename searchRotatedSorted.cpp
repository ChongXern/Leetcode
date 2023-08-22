/**
 * https://leetcode.com/problems/search-in-rotated-sorted-array
 * Array, Binary Search
 * Medium
*/
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int binarySearch(vector<int>& nums, int target, int left, int right) {
        // Assume not rotated
        if (left > right) {
            return -1;
        }
        int mid = left + (right - left) / 2;
        if (nums[mid] == target) {
            return mid;
        }
        if (nums[mid] > target) {
            return binarySearch(nums, target, left, mid - 1);
        }
        return binarySearch(nums, target, mid + 1, right);
    }
    int findSmallest(vector<int>& nums, int left, int right) {
        if (left == right || nums[left] < nums[right]) {
            return left;
        }
        int mid = left + (right - left) / 2;
        if (nums[mid] < nums[left]) {
            return findSmallest(nums, left, mid);
        }
        return findSmallest(nums, mid + 1, right);
    }
    int search(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size() - 1;
        int smallest = findSmallest(nums, left, right);
        return max(binarySearch(nums, target, left, smallest - 1), binarySearch(nums, target, smallest, right));
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
    int numsSize, target;
    cout << "Input size of array: ";
    cin >> numsSize;
    int *numsArr = new int[numsSize];
    int num;
    cout << "Input array:" << endl;
    for (int i = 0; i < numsSize; i++) {
        cin >> num;
        numsArr[i] = num;
    }
    vector<int> nums = vectorFromArray(numsArr, numsSize);
    cout << "Input target value: ";
    cin >> target;
    Solution solution;
    cout << solution.search(nums, target) << endl;
}

