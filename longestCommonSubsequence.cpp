/**
 * https://leetcode.com/problems/longest-common-subsequence/description/
 * String, Dynamic Programming
 * Medium
 */
#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int size1 = text1.size();
        int size2 = text2.size();
        int max = 0;
        for (int i = 0; i < size1; i++) {
            for (int j = 0; j < size2 - 1; j++) {
                int curr = 0;
				while (i + curr < size1 && j + curr < size2 && text1[i + curr] == text2[i + curr]) {
				   curr++;
				}
				if (curr > max) {
				   max = curr;
				}
            }
        }
        return max;
    }
};

int main() {
   string text1, text2;
   cout << "Input text1 and text2:" << endl;
   cin >> text1 >> text2;
   Solution solution;
   int longestCommonSubsequence = solution.longestCommonSubsequence(text1, text2);
   cout << "Longest common subsequence for " << text1 << " and " << text2 << ": " << longestCommonSubsequence << endl;
}
