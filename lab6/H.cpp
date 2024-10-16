#include <iostream>
using namespace std;

void binsearch(char a[], char t, int n) {
    int l = 0, r = n - 1;
    int res = -1;
    while (l <= r) {
        int mid = l + (r - l)/2;
        if (a[mid] <= t) {
            l = mid + 1;
        }
        if (a[mid] > t) {
            res = mid;
            r = mid - 1;
        }
    }
    if (res != -1)
        cout << a[res];
    else
        cout << a[0];
}

int main() {
    int n; cin >> n;
    char a[n];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    char target; cin >> target;
    binsearch(a, target, n);
}