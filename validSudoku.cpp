/**
 * https://leetcode.com/problems/valid-sudoku/
 * Array, Hash Table, Matrix
 * Medium
*/
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool checkRow(vector<vector<char> >& board, int row, int col) {
        char num = board[row][col];
        for (int i = 0; i < 9; i++) {
            if (i == col) {
                continue;
            }
            if (num == board[row][i]) {
                return false;
            }
        }
        return true;
    }
    bool checkCol(vector<vector<char> >& board, int row, int col) {
        char num = board[row][col];
        for (int i = 0; i < 9; i++) {
            if (i == row) {
                continue;
            }
            if (num == board[i][col]) {
                return false;
            }
        }
        return true;
    }
    bool checkBox(vector<vector<char> >& board, int row, int col) {
        char num = board[row][col];
        for (int i = (row / 3) * 3; i < (row / 3) * 3 + 3; i++) {
            for (int j = (col / 3) * 3; j < (col / 3) * 3 + 3; j++) {
                if (i == row && j == col) {
                    continue;
                }
                if (num == board[i][j]) {
                    return false;
                }
            }
        }
        return true;
    }
    bool checkAll(vector<vector<char> >& board, int row, int col) {
        if (!checkRow(board, row, col) || !checkCol(board, row, col) || !checkBox(board, row, col)) {
            cout << row << " " << col;
            return false;
        }
        return true;
    }
    bool isValidSudoku(vector<vector<char> >& board) {
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                if (board[i][j] == '.') {
                    continue;
                }
                if (!checkAll(board, i, j)) {
                    return false;
                }
            }
        }
        return true;
    }
};

int main() {
	vector<vector<char> > board;
	cout << "Input sudoku:" << endl;
    char read;
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			cin >> read;
            board[i][j] = read;
		}
	}
	Solution solution;
	if (solution.isValidSudoku(board)) {
		cout << "is valid sudoku" << endl;
	} else {
		cout << "is not valid sudoku" << endl;
	}
}
