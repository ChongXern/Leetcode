/**
 * https://leetcode.com/problems/maximum-area-of-a-piece-of-cake-after-horizontal-and-vertical-cuts
 * Array, Greedy Sorting
 * Medium
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int maxArea(int h, int w, vector<int>& horizontalCuts, vector<int>& verticalCuts) {
        sort(horizontalCuts.begin(), horizontalCuts.end());
        sort(verticalCuts.begin(), verticalCuts.end());
        int hCutsSize = horizontalCuts.size();
        int vCutsSize = verticalCuts.size();
        long maxHCut = (long)max(horizontalCuts[0], h - horizontalCuts[hCutsSize - 1]);
        for (int i = 1; i < hCutsSize; i++) {
            long hDiff = (long)(horizontalCuts[i] - horizontalCuts[i - 1]);
            if (hDiff > maxHCut) {
                maxHCut = hDiff;
            }
        }
        long maxVCut = (long)(max(verticalCuts[0], w - verticalCuts[vCutsSize - 1]));
        for (int i = 1; i < vCutsSize; i++) {
            long vDiff = (long)(verticalCuts[i] - verticalCuts[i - 1]);
            if (vDiff > maxVCut) {
                maxVCut = vDiff;
            }
        }
        long ans = (maxHCut * maxVCut) % 1000000007;
        return (int)ans;
    }
};

int main() {
    int h, w;
    cout << "h: ";
    cin >> h;
    cout << "w: ";
    cin >> w;
    vector<int> hCuts, vCuts;
    cout << "Horizontal cuts:" << endl;
    int cut;
    while (cin >> cut && cut > 0) {
        hCuts.push_back(cut);
    }
    cout << "Vertical cuts:" << endl;
    while (cin >> cut && cut > 0) {
        vCuts.push_back(cut);
    }
    Solution solution;
    int maxArea = solution.maxArea(h, w, hCuts, vCuts);
    cout << "Maximum area = " << maxArea << endl;
}

