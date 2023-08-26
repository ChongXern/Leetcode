/**
 * https://leetcode.com/problems/min-cost-climbing-stairs/
 * Array, Dynamic Programming
 * Easy
 */
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	/*
	// Top down memoization dynamic programming approach
    int minCostClimbingStairs(vector<int>& cost) {
        int size = cost.size();
        vector<int> dp;
        dp.assign(size + 1, -1);
        dp[0] = cost[0];
        dp[1] = cost[1];
        for (int i = 2; i < size; i++) {
            dp[i] = cost[i] + min(dp[i - 1], dp[i - 2]);
        }
        int zero = dp[size - 1];
        cout << "Start at 0: " << zero << endl;
        int one = dp[size - 2];
        cout << "Start at 1: " << one << endl;
        return min(zero, one);
    }*/
	// Faster approach
	int minCostClimbingStairs(vector<int>& cost) {
		int size = cost.size();
		int first = cost[0];
		int second = cost[1];
		int curr = min(first, second);
		for (int i = 2; i < size; i++) {
			curr = cost[i] + min(first, second);
			first = second;
			second = curr;
		}
		return min(first, second);
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
	int size, elem;
	cout << "Input size of array: ";
	cin >> size;
	int *array = new int[size];
	cout << "Input array:" << endl;
	for (int i = 0; i < size; i++) {
		cin >> elem;
		array[i] = elem;
	}
	vector<int> cost = vectorFromArray(array, size);
	Solution solution;
	int minCost = solution.minCostClimbingStairs(cost);
	cout << "Minimum cost: " <<  minCost << endl;
}
