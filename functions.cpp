#include "functions.h"
#include <iostream>
#include <vector>
using namespace std;

vector<int> vectorFromArray(int* array, int len) {
   vector<int> vector;
   for (int i = 0; i < len; i++) {
	  vector.push_back(array[i]);
   }
   return vector;
}

int main() {
   int arrLen;
   cout << "Input length of array: ";
   cin >> arrLen;
   int *arr = new int[arrLen];
   cout << "Input array:" << endl;
   int elem;
   for (int i = 0; i < arrLen; i++) {
	  cin >> elem;
	  arr[i] = elem;
   }
   vector<int> vect = vectorFromArray(arr, arrLen);
   cout << "Vector:" << endl;
   for (int vectElem : vect) {
	  cout << vectElem << ' ';
   }
   cout << endl;
}
