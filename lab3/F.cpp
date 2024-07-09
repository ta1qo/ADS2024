#include<iostream>
#include<algorithm>
using namespace std;

int binary_search(int powers[], int left, int right, int mark) {
    if (left > right) return left;

    int mid = left + (right - left) / 2;
    if (powers[mid] > mark) return binary_search(powers, left, mid - 1, mark);
    else return binary_search(powers, mid + 1, right, mark);
}

int total_Sum(int powers[], int cnt) {
    int sum = 0;
    for (int i = 0; i < cnt; i++) {
        sum += powers[i];
    }
    return sum;
}
int main() {
    int n; 
    cin >> n;
    int powers[n];
    for (int i = 0; i < n; i++) {
        cin >> powers[i];
    }
    sort(powers, powers + n);
    int rounds;
    cin >> rounds;
    while (rounds--) {
        int mark;
        cin >> mark;
        int cnt = binary_search(powers, 0, n-1, mark);
        int sum = total_Sum(powers, cnt);
        cout << cnt << " " << sum << "\n";
    }
    return 0;
}