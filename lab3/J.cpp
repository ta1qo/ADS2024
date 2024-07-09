#include<iostream>
#include<algorithm>
using namespace std;

bool canSteal(int bags[], int n, int mid, int h) {
    int hours = 0;
    for (int i = 0; i < n; i++) {
        hours += (bags[i] + mid - 1) / mid;
    }
    return hours <= h;
}

int main() {
    int n, h; 
    cin >> n >> h; 
    int bags[n];
    for (int i = 0; i < n; i++) {
        cin >> bags[i];
    }

    int left = 1, right = *max_element(bags, bags + n);
    int k = right;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (canSteal(bags, n, mid, h)) {
            k = mid;
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }
    cout << k;
    return 0;
}