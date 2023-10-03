#include <iostream>
using namespace std;

int partition(int* arr, int start, int end) {
    int pivot = arr[start];
    int low = start + 1;
    int high = end;
    while (true) {
        while (low <= high && arr[low] <= pivot) {low++;}
        while (low <= high && arr[high] > pivot) {high--;}        
        if (low <= high) {
            swap(arr[low], arr[high]);
        } else {
            break;
        }
    }

    swap(arr[start], arr[high]);
    return high;
}

void quickSort(int* arr, int start, int end) {
    if (start < end) {
        int pivotIndex = partition(arr, start, end);
        quickSort(arr, start, pivotIndex - 1);
        quickSort(arr, pivotIndex + 1, end);
    }
}


/**
 * 4 3 2 1
 * 4 4 2 1
 * 3 4 2 1
 * 
 * 
*/


int main() {
    int n;
    cout << "Input n: ";
    cin >> n;
    int* arr = new int(n);
    cout << "Input array:" << endl;
    int elem;
    for (int i = 0; i < n; i++) {
        cin >> elem;
        arr[i] = elem;
    }
    quickSort(arr, 0, n - 1);
    for (int i = 0; i < n; i++) {
        cout << arr[i] << ' ';
    }
    cout << endl;
}