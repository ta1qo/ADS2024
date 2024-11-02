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

void rabinKarp(string s1, string s2, string t) {
    int n = s1.length(), m = s2.length(), k = t.length();
    int hash_s1 = getHash(s1.substr(0, k));
    int hash_s2 = getHash(s2.substr(0, k));
    int hash_t = getHash(t);
    int power = 1;
    for (int i = 0; i < k - 1; i++) {
        power *= PRIME;
    }
    int cnt = 0;
    for (int i = 0; i + k <= n && i + k <= m; i++) {
        if (hash_s1 == hash_t && hash_s2 == hash_t) {
            cnt++;
        }
        if (i + k < n && i + k < m) {
            hash_s1 = (hash_s1 - power * (s1[i] - 'a' + 1)) * PRIME + (s1[i + k] - 'a' + 1);
            hash_s2 = (hash_s2 - power * (s2[i] - 'a' + 1)) * PRIME + (s2[i + k] - 'a' + 1);
        }
    }
    cout << cnt;
}

int main() {
    string s1, s2, t; cin >> s1 >> s2 >> t;
    rabinKarp(s1, s2, t);
    return 0;
}