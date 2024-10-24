#include <iostream>
using namespace std;
// Binary search is a search algorithm that is faster than the linear search algorithm. 
// Binary search is used to find the position of a target element in a sorted array by repeatedly dividing the search space in half. 
// With each comparison, binary search removes half of the array.
// Time Complexity: O(log n)
// Auxiliary Space: O(1)
int binarySearch(int arr[], int left, int right, int k) {
    if (left <= right) {
        int mid = left + (right - left) / 2;
        if (arr[mid] == k) return mid;
        else if (arr[mid] > k) return binarySearch(arr, left, mid - 1, k);
        else return binarySearch(arr, mid + 1, right, k);
    }
    return -1; 
}

int main() {
    int n; cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    int k; cin >> k;
    cout << binarySearch(arr, 0, n - 1, k);
    return 0;
}