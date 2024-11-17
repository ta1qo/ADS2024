#include <iostream>
using namespace std;

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

void quickSort(int arr[], int low, int high) {
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
    quickSort(arr, 0, n - 1);
    // for (int i= 0; i < n; i++) {
    //     cout << arr[i] << ' ';
    // }
    // cout << endl;
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        if (arr[i] != arr[i + 1]) {
            cnt++;
        }
    }
    cout << cnt;    
    return 0;
}