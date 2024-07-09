#include<iostream>
using namespace std;

int binary_search(int arr[], int left, int right, int k) {
    if (left > right) return left;

    int mid = left + (right - left) / 2;

    if (arr[mid] == k) return mid;
    else if (arr[mid] > k) return binary_search(arr, left, mid - 1, k);
    else return binary_search(arr, mid + 1, right, k);
}

int main() {
    int n, m; // blocks and mistakes
    cin >> n >> m;
    int p[n], sum = 0; // lines in the i-th block
    for (int i = 0; i < n; i++) {
        int a; cin >> a;
        sum += a;
        p[i] = sum;
    }
    while (m--) {
        int b; cin >> b;
        cout << binary_search(p, 0, n-1, b) + 1 << endl;
    }
    return 0;
}