/**
* https://leetcode.com/problems/n-queens/
* Array, Backtracking
* Hard
*/
#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
private:
   void printBoard(vector<string>& board, int n) {
	  for (int i = 0; i < n; i++) {
		 cout << board[i] << endl;
	  }
	  cout << endl;
   }
public:
   void swapRows(string &row1, string &row2) {
	  string temp = row1;
	  row1 = row2;
	  row2 = temp;
   }
   bool isSafe(vector<string> &board, int n, int row, int col) { 
	  // Check within row
	  for (int i = 0; i < n; i++) {
		 if (i == col) {
			continue;
		 }
		 if (board[row][i] == 'Q') {
			return true;
		 }
	  }
	  // Check within col
	  for (int i = 0; i < n; i++) {
		 if (i == row) {
			continue;
		 }
		 if (board[i][col] == 'Q') {
			return true;
		 }
	  }
	  // Check / Note: have to find better way to do this
	  // Check from middle to top rows
	  int currColPos = col + 1;
	  int currColNeg = col - 1;
	  for (int i = row - 1; i >= 0 && currColPos < n && currColNeg >= 0; i--) {
		 if (board[row][currColPos] == 'Q' || board[row][currColNeg] == 'Q') {
			return true;
		 }
		 currColPos++;
		 currColNeg--;
	  }
	  // Check from middle to bottom rows
	  currColPos = col - 1;
	  currColNeg = col + 1;
	  for (int i = row + 1; i < n && currColPos >= 0 && currColNeg < n; i++) {
		 if (board[row][currColPos] == 'Q' || board[row][currColNeg] == 'Q') {
			return true;
		 }
		 currColPos--;
		 currColNeg++;
	  } // DRY moment
	  return false;
   }
   bool isBoardSafe(vector<string>& board, int n) {
	  for (int row = 0; row < n; row++) {
		 for (int col = 0; col < n; col++) {
			if (!isSafe(board, n, row, col)) {
			   return false;
			}
		 }
	  }
	  return true;
   }
   vector<vector<string> > solveNQueens(int n) {
		vector<string> board;
		for (int i = 0; i < n; i++) {
		   string currStr = "";
		   for (int j = 0; j < n; j++) {
			  if (i == j) {
				 currStr += "Q";
			  } else {
			  	currStr += ".";
			  }
		   }
		   board.push_back(currStr);
		}
		vector<vector<string> > solutions;
		for (int i = 0; i < n; i++) {
		   for (int j = 0; j < n; j++) {
			  swapRows(board[i], board[j]);
			  printBoard(board, n);
			  if (isBoardSafe(board, n)) {
				 solutions.push_back(board);
			  }
			  swapRows(board[i], board[j]);
		   }
		}
		return solutions;
    }
};

int main() {
   int n;
   cout << "Input n: ";
   cin >> n;
   Solution solution;
   vector<vector<string> > nQueens = solution.solveNQueens(n);
   cout << "Answer to nQueens: " << endl;
   for (int i = 0; i < nQueens.size(); i++) {
	  for (int j = 0; j < nQueens[0].size(); j++) {
		 cout << nQueens[i][j] << endl;
	  }
	  cout << endl;
   }
}
