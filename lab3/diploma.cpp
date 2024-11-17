#include <iostream>
using namespace std;

int main() {
    long long w, h, n;cin >> w >> h >> n;
    long long low = 1;
    long long high = max(w, h) * n;
    long long ans = high;
    while (low <= high) {
        long long mid = (low + high) / 2;
        if ((mid / w) * (mid / h) >= n) {
            ans = mid; 
            high = mid - 1;  
        } else {
            low = mid + 1; 
        }
    }
    
    cout << ans << endl;
    return 0;
}