#include<iostream>
using namespace std;

int binary_search_inc(int arr[], int left, int right, int k) {
    if (left > right) return -1;

    int mid = left + (right - left) / 2;

    if (arr[mid] == k) return mid;
    else if (arr[mid] > k) return binary_search_inc(arr, left, mid - 1, k);
    else return binary_search_inc(arr, mid + 1, right, k);
}

int binary_search_dec(int arr[], int left, int right, int k) {
    if (left > right) return -1;

    int mid = left + (right - left) / 2;

    if (arr[mid] == k) return mid;
    else if (arr[mid] > k) return binary_search_dec(arr, mid + 1, right, k);
    else return binary_search_dec(arr, left, mid - 1, k);
}


int main() {
    int t; cin >> t;
    int arr[t];
    for (int i = 0; i < t; i++) {
        cin >> arr[i];
    }

    int n, m;
    cin >> n >> m;
    int snake[n][m];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> snake[i][j];
        }
    }

    int i = 0, y;
    while (i < t) {
        for (int x = 0; x < n; x++) {
            if (x % 2 != 0) {
                y = binary_search_inc(snake[x], 0, m - 1, arr[i]);
            } else {
                y = binary_search_dec(snake[x], 0, m - 1, arr[i]);
            }
            if (y != -1) {
                cout << x << ' '<< y << endl;
                break;
            }
        }
        if (y == -1) {
            cout << y << endl;
        }        
        i++;
    }

    return 0;
}