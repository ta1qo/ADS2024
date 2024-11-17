#include <iostream>
#include <vector>
#define ll long long
using namespace std;

void LPS(string &pat, vector<ll> &lps) {
    ll len = 0;
    ll i = 1;
    while (i < pat.length()) {
        if (pat[i] == pat[len]) {
            lps[i] = len + 1;
            len++;
            i++;
        } else if (len != 0) {
            len = lps[len - 1];  
        } else {
            lps[i] = 0;
            i++;
        }
    }
}

ll KMP(string &sub, ll &k) {
    ll n = sub.length();
    vector<ll> lps(n, 0);
    LPS(sub, lps);
    ll len = (n - lps[n - 1]) * (k - 1) + n;
    return len;
}

int main() {
    ll t; cin >> t;
    while (t--) {
        string s; cin >> s;
        ll k; cin >> k;
        cout << KMP(s, k) << endl;
    }

    return 0;
}