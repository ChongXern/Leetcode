/**
 * https://leetcode.com/problems/zigzag-conversion/
 * String
 * Medium
*/
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    void updateMatrix(char letter, vector<vector<char> >& matrix, int numRows, int numCols, int& i, int& j, char& lastDir) {
        matrix[i][j] = letter;
        //cout << i << ' ' << j << ' ' << letter << endl;
        if (i == 0) {
            lastDir = 'd';
        }
        else if (i == numRows - 1) {
            lastDir = 'u';
        }
        if (lastDir == 'd') {
            i++;
        } else {
            i--;
            j++;
        }
    }
    string convert(string s, int numRows) {
        int numCols = s.size();
        vector<vector<char> > matrix(numRows, vector<char>(numCols));
        int i = 0, j = 0;
        char lastDir = 'd';
        for (int pos = 0; pos < numCols; pos++) {
            updateMatrix(s[pos], matrix, numRows, numCols, i, j, lastDir);
        }
        string zigzag;
        for (int i = 0; i < numRows; i++) {
            for (int j = 0; j < numCols; j++) {
                zigzag += matrix[i][j];
            }
        }
        return zigzag;
    }
};

int main() {
    string s;
    int numRows;
    cout << "Input string: ";
    cin >> s;
    cout << "Input number of rows: ";
    cin >> numRows;
    Solution solution;
    string zigzag = solution.convert(s, numRows);
    cout << zigzag << endl;
}
