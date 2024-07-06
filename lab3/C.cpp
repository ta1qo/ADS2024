#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int count_in_range(vector<int>& v, int left, int right) {
    return upper_bound(v.begin(), v.end(), right) - lower_bound(v.begin(), v.end(), left);
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
        int l1, r1, l2, r2;
        cin >> l1 >> r1 >> l2 >> r2;
        int cnt1 = count_in_range(v, l1, r1);
        int cnt2 = count_in_range(v, l2, r2);
        int cnt = 0;
        if (l1 <= r2 && l2 <= r1) {
            int l = max(l1, l2);
            int r = min(r1, r2);
            cnt = count_in_range(v, l, r);
        }
        cout << cnt1 + cnt2 - cnt << endl;
    }
    return 0;
}
// #include<iostream>
// using namespace std;

// int num_of_indices(int arr[], int n, int l1, int r1, int l2, int r2) {
//     int cnt = 0;
//     for (int i = 0; i < n; i++) {
//         if ((l1 <= arr[i] && arr[i] <= r1) || (l2 <= arr[i] && arr[i] <= r2)) {
//             cnt++;
//         }
//     }
//     return cnt;
// }

// int main() {
//     int n, q;
//     cin >> n >> q;
//     int arr[n];
//     for (int i = 0; i < n; i++) {
//         cin >> arr[i];
//     }
//     while (q--) {   
//         int l1, r1, l2, r2;
//         cin >> l1 >> r1 >> l2 >> r2;
//         int c = num_of_indices(arr, n, l1, r1, l2, r2);
//         cout << c << endl;
//     }
//     return 0; 
// }