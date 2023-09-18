/**
 * https://leetcode.com/problems/equal-row-and-column-pairs
 * Array, Hash Table, Matrix, Simulation
 * Medium
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool isEqual(vector<vector<int> >& grid, int n, int row, int col) {
        for (int i = 0; i < n; i++) {
            if (grid[row][i] != grid[i][col]) {
                return false;
            }
        }
        return true;
    }
    int equalPairs(vector<vector<int> >& grid) {
        int n = grid.size();
        int counter = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (isEqual(grid, n, i, j)) {
                    counter++;
                }
            }
        }
        return counter;
    }
};

template <class T>
vector<T> convertToVector(T* arr, int n) {
	vector<T> vec;
	for (int i = 0; i < n; i++) {
		vec.push_back(arr[i]);
	}
	return vec;
}

template <class T>
vector<vector<T> > convertToMatrix(T** arr, int n) {
	vector<vector<T> > mat;
	for (int i = 0; i < n; i++) {
		mat.push_back(convertToVector(arr[i], n));
	}
	return mat;
}

int main() {
	int n;
	cout << "Input n: ";
	cin >> n;
	int** matArr = new int*[n];
	for (int i = 0; i < n; i++) {
		matArr[i] = new int[n];
	}
	cout << "Input matrix:" << endl;
	int elem;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> elem;
			matArr[i][j] = elem;
		}
	}
	vector<vector<int> > mat = convertToMatrix<int> (matArr, n);
	Solution solution;
	int equalPairs = solution.equalPairs(mat);
	cout << equalPairs << endl;
}

