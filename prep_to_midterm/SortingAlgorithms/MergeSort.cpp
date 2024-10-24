#include <iostream>
using namespace std;
// Merge Sort is an efficient sorting method that is based on the principle of divide and conquer. 
// It divides the original array into two equal (or nearly equal) parts, sorts each of them separately, and then sorts them back into a sorted array. 
// The merging process allows you to extract the two sorted subarrays into a single sorted array.
// Time Complexity: best case = avg case = worst case =  O(n log n)
// Space Complexity: O(n) 
void mergeHalves(int arr[], int temp[], int leftStart, int rightEnd) {
    int leftEnd = leftStart + (rightEnd - leftStart) / 2;
    int rightStart = leftEnd + 1;

    int left = leftStart;
    int right = rightStart;
    int index = leftStart;

    while (left <= leftEnd && right <= rightEnd) {
        if (arr[left] <= arr[right]) {
            temp[index] = arr[left];
            left++;
        } else {
            temp[index] = arr[right];
            right++;
        }

        index++;
    }

    while (left <= leftEnd) {
        temp[index] = arr[left];
        index++; left++;
    }

    while (right <= rightEnd) {
        temp[index] = arr[right];
        index++; right++;
    }

    for (int i = leftStart; i <= rightEnd; i++) {
        arr[i] = temp[i];
    }
}

void mergeSort(int arr[], int temp[], int leftStart, int rightEnd) {
    if (leftStart < rightEnd) {
        int middle = leftStart + (rightEnd - leftStart) / 2;
        mergeSort(arr, temp, leftStart, middle);
        mergeSort(arr, temp, middle + 1, rightEnd);
        mergeHalves(arr, temp, leftStart, rightEnd);
    }
}

int main() {
    int n; cin >> n;
    int arr[n];
    int temp[n];
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    mergeSort(arr, temp, 0, n - 1);  
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    return 0;
}