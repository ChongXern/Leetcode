/**
 * 
*/
#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    string countAndSay(int n) {
        if (n == 1) {
            return "1";
        } 
        string output = "";
        string prev = countAndSay(n - 1);
        char currNum = prev[0];
        int currCount  = 0;
        for (char num : prev) { 
            if (num == currNum) {
                currCount++;
            } else {
                output += currCount + '0';
                output += currNum;
                currNum = num;
                currCount = 1;
            }
        } 
        output += currCount + '0';
        output += currNum;
        return output;
    }
};

int main() {
    int n;
    cout << "Input n:" << endl;
    cin >> n;
    Solution solution;
    string countAndSay = solution.countAndSay(n);
    cout << countAndSay << endl;
}