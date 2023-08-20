/**
 * https://leetcode.com/problems/n-queens/
 * Array, Backtracking
 * Hard
 */
#include <iostream>
#include <vector>
#include <string>
#include <chrono>
#include <thread>
using namespace std;

class Solution {
   private:
	  void printBoard(vector<string>& board, int n) {
		 system("clear");
		 for (int i = 0; i < n; i++) {
			cout << board[i] << endl;
		 }
		 cout << endl;
		 std::this_thread::sleep_for(std::chrono::milliseconds(100));
	  }

   public:
	  bool isSafe(vector<string> &board, int n, int row, int col) { 
		 // Note: have to find better way to do this
		 // Check from middle to top rows
		 int currColPos = col + 1;
		 int currColNeg = col - 1;
		 for (int i = row - 1; i >= 0; i--) {
			if ((currColPos < n && board[i][currColPos] == 'Q') || (currColNeg >= 0 && board[i][currColNeg] == 'Q')) {
			   return false;
			}
			currColPos++;
			currColNeg--;
		 }
		 // Check from middle to bottom rows
		 currColPos = col - 1;
		 currColNeg = col + 1;
		 for (int i = row + 1; i < n; i++) {
			if ((currColPos >= 0 && board[i][currColPos] == 'Q') || (currColNeg < n && board[i][currColNeg] == 'Q')) {
			   return false;
			}
			currColPos--;
			currColNeg++;
		 } // DRY moment
		 return true;
	  }

	  bool isBoardSafe(vector<string>& board, int n) {
		 for (int row = 0; row < n; row++) {
			for (int col = 0; col < n; col++) {
			   if (board[row][col] == '.') {
				  continue;
			   }
			   if (!isSafe(board, n, row, col)) {
				  return false;
			   }
			}
		 }
		 return true;
	  }

	  void backtrack(vector<vector<string> >& solutions, vector<string>& board, int start, int n) {
		 if (start == n - 1) {
			//solutions.push_back(board);
			return;
		 }
		 for (int i = start; i < n; i++) {
		   swap(board[start], board[i]);
		   // printBoard(board, n);
		   backtrack(solutions, board, start + 1, n);
		   if (isBoardSafe(board, n)) {
			  solutions.push_back(board);
		   }
		   swap(board[start], board[i]);
		 }
	  }

	  vector<vector<string> > solveNQueens(int n) {
		 vector<string> board;
		 vector<vector<string> > solutions;
		 if (n == 1) {
			board.push_back("Q");
			solutions.push_back(board);
			return solutions;
		 }
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
		 backtrack(solutions, board, 0, n);
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
   cout << nQueens.size() << " solutions" << endl;
   /*
   vector<string> test = { "Q.", ".Q"};
   if (solution.isSafe(test, 2, 0, 0)) {
	  cout << "Test board is safe" << endl;
   } else {
	  cout << "Test board is unsafe" << endl;
   }*/
}
