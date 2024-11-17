#include <iostream>
using namespace std;

int partition(int arr[], int left, int right, int pivot) {
    while (left <= right) {
        while (arr[left] < pivot) left++;
        while (arr[right] > pivot) right--;
        if (left <= right) {
            swap(arr[left], arr[right]);
            left++;
            right--;
        }
    }
    return left;
}

void quickSort(int arr[], int left, int right) {
    if (left >= right) return;
    int pivot = arr[(left+right)/2];
    int index = partition(arr, left, right, pivot);
    quickSort(arr, left, index-1);
    quickSort(arr, index, right);
}

int main() {
    int n; cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    quickSort(arr, 0, n - 1);
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    return 0;
}