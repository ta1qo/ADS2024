#include <iostream>
#include <algorithm>
#define ll long long
using namespace std;

bool canPartition(ll arr[], ll n, ll mid, ll k) {
    ll cnt = 0, sum = 0;
    for (ll i = 0; i < n; i++) {
        sum += arr[i];
        if (sum > mid) {
            cnt++;
            sum = arr[i];
        }
    }
    return cnt + 1 <= k;
}

int main() {
    ll n, k;
    cin >> n >> k;
    
    ll arr[n];
    ll sum = 0;
    for (ll i = 0; i < n; i++) {
        cin >> arr[i];
        sum += arr[i];
    }

    ll left = *max_element(arr, arr + n);
    ll right = sum;
    ll min_poss_max = sum;

    while (left <= right) {
        ll mid = left + (right - left) / 2;
        if (canPartition(arr, n, mid, k)) {
            min_poss_max = mid;
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }

    cout << min_poss_max << endl;

    return 0;
}