#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool canPartition(const vector<int>& v, int mid, int k) {
    int cnt = 1, sum = 0;
    for (int i = 0; i < v.size(); i++) {
        sum += v[i];
        if (sum > mid) {
            cnt++;
            if (cnt > k) {
                return false;
            }
            sum = v[i];
        }
    }
    return true;
}

int main() {
    int n, k;
    cin >> n >> k;
    
    vector<int> v(n);
    int sum = 0;
    for (int i = 0; i < n; i++) {
        cin >> v[i];
        sum += v[i];
    }

    int left = *max_element(v.begin(), v.end());
    int right = sum;
    int min_poss_max = sum;

    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (canPartition(v, mid, k)) {
            min_poss_max = mid;
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }

    cout << min_poss_max << endl;

    return 0;
}