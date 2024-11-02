#include <iostream>
using namespace std;

int MOD = 1e9 + 7;
int PRIME = 31;

int getHash(string s) {
    int hash = 0;
    for (int i = 0; i < s.size(); i++) {
        hash = hash * PRIME + (s[i] - 'a' + 1);
    }
    return hash;
}

void rabinKarp(string s, string t) {
    int n = s.length(), m = t.length();
    int hash_s = getHash(s.substr(0, m));
    int hash_t = getHash(t);
    int power = 1;
    for (int i = 0; i < m - 1; i++) {
        power *= PRIME;
    }
    int cnt = 0;
    for (int i = 0; i + m <= n; i++) {
        if (hash_s == hash_t) {
            cnt++;
        }
        if (i + m < n) {
            hash_s = (hash_s - power * (s[i] - 'a' + 1)) * PRIME + (s[i + m] - 'a' + 1);
        }
    }
    cout << cnt << endl;
}

int main() {
    string s, t; cin >> s; 
    int q; cin >> q;
    while (q--) {
        int l, r; cin >> l >> r;
        t = s.substr(l - 1, r - l + 1);
        rabinKarp(s, t);
    }

    return 0;
}