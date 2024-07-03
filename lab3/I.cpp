#include<iostream>
using namespace std;

string binary_search(int arr[], int left, int right, int k) {
    if (left > right) return "No";

    int mid = left + (right - left) / 2;

    if (arr[mid] == k) return "Yes";
    else if (arr[mid] > k) return binary_search(arr, left, mid - 1, k);
    else return binary_search(arr, mid + 1, right, k);
}

int main() {
    int n; cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    
    int k; cin >> k;
    cout << binary_search(arr, 0, n - 1, k);

    return 0;
}