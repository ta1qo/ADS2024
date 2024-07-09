#include<iostream>
#include<algorithm>
using namespace std;

bool canDeliver(int arr[], int n, int f, int cap) {
    int flights = 0;
    for (int i = 0; i < n; i++) {
        flights += (arr[i] + cap - 1) / cap;
    }
    return flights <= f;
}

int main() {
    int n, f;
    cin >> n >> f;
    int arr[n];
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    int left = 1, right = *max_element(arr, arr + n);
    int leastCappacity = right;

    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (canDeliver(arr, n, f, mid)) {
            leastCappacity = mid;
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }
    cout << leastCappacity;
    return 0;
}