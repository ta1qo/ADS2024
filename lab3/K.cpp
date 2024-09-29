#include<iostream>
#include<vector>
#include<climits>
using namespace std;

int minSubarrayLength(int n, int k, vector<int>& arr) {
    int minLength = INT_MAX;
    int sum = 0;
    int current = 0;

    for (int i = 0; i < n; i++) {
        sum += arr[i];
        
        while (sum >= k) {
            minLength = min(minLength, i - current + 1);
            sum -= arr[current];
            current++;
        }
    }

    return minLength;
}

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    cout << minSubarrayLength(n, k, arr);

    return 0;
}
