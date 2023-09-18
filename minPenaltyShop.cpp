#include <iostream>
#include <string>
#include <queue>
using namespace std;

class Solution {
public:
    int bestClosingTime(string customers) {
        int minimum = 0;
        for (int i = 0; i < customers.size(); i++) {
            if (customers[i] == 'Y') {
                minimum++;
            }
        }
        cout << minimum << endl;
        int curr = minimum;
        for (int i = 0; i < customers.size(); i++) {
            if (customers[i] == 'Y') {
                curr--;
            } else {
                curr++;
            }
            if (curr < minimum) {
                minimum = curr;
            }
        }
        return minimum;
    }
};

int main() {
    string customers;
    cout << "Input customers:" << endl;
    cin >> customers;
    Solution solution;
    int best = solution.bestClosingTime(customers);
    cout << best << endl;
}