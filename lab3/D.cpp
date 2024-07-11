#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int lower_bound(vector<int>& arr, int n, int x) {
    int left = 0, right = n - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;        
        if (arr[mid] >= x) {
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    } 
    return left;
}

int upper_bound(vector<int>& arr, int n, int x) {
    int left = 0, right = n - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;        
        if (arr[mid] <= x) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return right;
}

int count_in_range(vector<int>& arr, int n, int x1, int y1, int x2, int y2) {
    int lower, upper, count = 0;

    lower = lower_bound(arr, n, x1);
    upper = upper_bound(arr, n, y1);
    count = upper - lower + 1;
    
    return count;
}

vector<int> non_overlap(int l1, int r1, int l2, int r2) {
    if ((r1 - l1) < (r2 - l2)) {
        int temp = r1;
        r1 = r2;
        r2 = temp;
        temp = l1;
        l1 = l2;
        l2 = temp;
    }
    if (r2 <= r1 && l2 >= l1 ) {
        return {l1, r1}; // действие только для одного интервала л1 р1
    } else if (r2 <= r1 && r2 >= l1 && l2 < l1) {
        r2 = l1 - 1; // перемешаем правый конец второго интервала перед началом второго интервала
    } else if (r2 > r1 && l2 < r1) {
        l2 = r1 + 1; // перемещаем левый конец второго интервала после конца второго интервала
    }
    return {l1, r1, l2, r2};
}

int main() {
    int n, q;
    cin >> n >> q;
    vector<int> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    sort(v.begin(), v.end());
    while (q--) {
        int l1, r1, l2, r2, res;
        cin >> l1 >> r1 >> l2 >> r2;
        vector<int> new_range = non_overlap(l1, r1, l2, r2);
        if (new_range.size() > 2) {
            res = (upper_bound(v, n, new_range[1]) - lower_bound(v, n, new_range[0]) + 1) + (upper_bound(v, n, new_range[3]) - lower_bound(v, n, new_range[2]) + 1);
        }
        else {
            res = upper_bound(v, n, new_range[1]) - lower_bound(v, n, new_range[0]) + 1;
        }
        cout << res << endl;
    }
    return 0;
}