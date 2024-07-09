#include<iostream>
#include <climits>
using namespace std;

bool can_cover(int arr[][4], int n, int l, int k) {
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        if (arr[i][2] <= l && arr[i][3] <= l) {
            cnt++;
        }
        if (cnt >= k) {
            return true;
        }
    }
    return false;
}

int binary_search(int arr[][4], int n, int k) {
    int left = 1, right = INT_MAX;
    int res;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (can_cover(arr, n, mid, k)) {
            res = mid;
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }
    return res;
}
int main() {
    int n, k;
    cin >> n >> k;
    int arr[n][4];
    for (int i = 0; i < n; i++) {
        cin >> arr[i][0] >> arr[i][1] >> arr[i][2] >> arr[i][3];
    }
    int min_length = binary_search(arr, n, k);
    cout << min_length;
    return 0;
}