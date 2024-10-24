#include <iostream>
using namespace std;
// QuickSort is a sorting algorithm based on the Divide and Conquer that picks an element as a pivot and 
// partitions the given array around the picked pivot by placing the pivot in its correct position in the sorted array.
// Time Complexity: best case = avg case = O(n log n), worst case = O(n²)
// Space Complexity: O(n) 
int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = low;
    for (int j = low; j < high; j++) {
        if (arr[j] <= pivot) {
            swap(arr[i], arr[j]);
            i++;
        }
    }
    swap(arr[i], arr[high]);
    return i;
}

void quickSort(int arr[], int left, int right) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);  
        quickSort(arr, pi + 1, high); 
    }
}

int main() {
    int n; cin >> n;
    int arr[n];
    for (int i= 0; i < n; i++) {
        cin >> arr[i];
    }
    qsort(arr, 0, n - 1);
    for (int i = 0; i < n; i++) {
        cout << arr[i] << ' ';
    }
    
    return 0;
}