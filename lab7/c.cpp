#include <iostream>
using namespace std;

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
        index++;
        left++;
    }

    while (right <= rightEnd) {
        temp[index] = arr[right];
        index++; 
        right++;
    }

    for (int i = leftStart; i <= rightEnd; i++) {
        arr[i] = temp[i];
    }
}

void mergeSort(int arr[], int temp[], int leftStart, int rightEnd) {
    if (leftStart >= rightEnd) return;

    int middle = leftStart + (rightEnd - leftStart) / 2;
    mergeSort(arr, temp, leftStart, middle);
    mergeSort(arr, temp, middle + 1, rightEnd);
    mergeHalves(arr, temp, leftStart, rightEnd);
}

int main() {
    int n, m; cin >> n >> m;
    int a[n], b[m];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < m; i++) {
        cin >> b[i];
    }
    mergeSort(a, new int[n], 0, n - 1);
    mergeSort(b, new int[m], 0, m - 1); 
    int i = 0, j = 0;
    while (i < n && j < m) {
        if (a[i] == b[j]) {
            cout << a[i] << ' ';
            i++;
            j++;
        } else if (a[i] < b[j]) {
            i++;
        } else {
            j++;
        }
    }

    return 0;
}