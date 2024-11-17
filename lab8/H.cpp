#include <iostream>
#include <cstdint>
#include <unordered_set>
#define ll long long
using namespace std;

const ll p = 31;

long long get_hash(string s) {
    ll h = 0;
    for (int i = 0; i < s.size(); i++) {
        h = (h * p + (s[i] - 'a' + 1));
    }
    return h;
}

bool rk(string s, string t) {
    int n = s.length(), m = t.length();
    int hs = get_hash(s.substr(0, m));
    int ht = get_hash(t);
    int pm = 1;
    for (int i = 0; i < m - 1; i++) {
        pm *= p;
    }
    for (int i = 0; i + m <= n; i++) {
        if (hs == ht)
            return true;
        if (i + m < n)
            hs = (hs - pm * (s[i] - 'a' + 1)) * p + (s[i + m] - 'a' + 1);
    }
    return false;
}

int main() {
    int n; cin >> n;
    string a[n];
    int min_size = INT32_MAX;
    string min_string;
    for (int i = 0; i < n; i++) {
        string s; cin >> s;
        if (min_size > s.size()) {
            min_size = s.size();
            min_string = s;
        }
        a[i] = s;
    }
    int max_size = 0;
    string res = "";
    for (int i = 0; i < min_size; i++) {
        for (int j = i; j < min_size; j++) {
            string sub = min_string.substr(i, min_size - j);
            bool ok = true;
            for (int k = 0; k < n; k++) {
                if (!rk(a[k], sub)) {
                    ok = false;
                    break;
                }
            }
            if (ok) {
                if (max_size < sub.size()) {
                    max_size = sub.size();
                    res = sub;
                }
            }
        }
    }
    cout << res;

    return 0;
}