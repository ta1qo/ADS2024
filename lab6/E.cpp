#include <iostream>
using namespace std;

int partition(int arr[], int left, int right) {
    int pivot = arr[right];
    int i = (left-1);
    for (int j = left; j <= right-1; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i+1], arr[right]);
    return (i+1);
}

void quickSort(int arr[], int left, int right) {
    if (left >= right) return;
    int index = partition(arr, left, right);
    quickSort(arr, left, index-1);
    quickSort(arr, index+1, right);
}

int main() {
    int n, m; cin >> n >> m;
    int arr[m][n];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> arr[j][i];
        }
    }
    for (int i = 0; i < m; i++) {
        quickSort(arr[i], 0, n - 1);
    }
    for (int i = n - 1; i >= 0; i--) {
        for (int j = 0; j < m; j++) {
            cout << arr[j][i] << " ";
        }
        cout << "\n";
    }
}