#include <iostream>
using namespace std;
// Heap sort is a comparison-based sorting technique based on Binary Heap Data Structure. 
// It can be seen as an optimization over selection sort where we first find the max (or min) element and swap it with the last (or first). 
// We repeat the same process for the remaining elements.
// Time Complexity: best case = avg case = worst case = O(n log n)
// Space Complexity: O(1) 
void heapify(int arr[], int n, int i) {
    int max = i;
    int left = 2*i + 1;
    int right = 2*i + 2;

    if (left < n && arr[left] > arr[max]) {
        max = left;
    }
    if (right < n && arr[right] > arr[max]) {
        max = right;
    }

    if (max != i) {
        swap(arr[i], arr[max]);
        heapify(arr, n, max);
    }
} 

void heapSort(int arr[], int n) {
    for (int i = n/2 - 1; i >= 0; i--) {
        heapify(arr, n, i);
    }
    for (int i = n - 1; i > 0; i--) {
        swap(arr[0], arr[i]);
        heapify(arr, i, 0);
    }
}

int main() {
    int n; cin >> n;
    int arr[n];
    for (int i = 0 ; i < n; i++) {
        cin >> arr[i];
    }
    heapSort(arr, n);
    for (int i = 0 ; i < n; i++) {
        cout << arr[i] << ' ';
    }
    return 0;
}