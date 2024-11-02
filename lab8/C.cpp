#include <iostream>
#include <vector>
#define ll long long
using namespace std;

const ll MOD = 1e9 + 7;
const ll PRIME = 31;

ll getHash(string text) {
    ll hash = 0, power = 1;
    for (int i = 0; i < text.size(); i++) {
        hash = (hash + (text[i] - 'a' + 1) * power) % MOD;
        power = (power * PRIME) % MOD;
    }
    return hash;
}

vector<ll> getPrefixHashes(string text) {
    vector<ll> hashCodes(text.size()); 
    ll hash = 0, power = 1;
    for (int i = 0; i < text.size(); i++) {
        hash = (hash + (text[i] - 'a' + 1) * power) % MOD;
        hashCodes[i] = hash;
        power = (power * PRIME) % MOD;
    }
    return hashCodes;
}

void rabinKarp(string text, string pattern, vector<size_t> &vec) {
    vector<ll> hashCodes = getPrefixHashes(text); 
    ll smallHash = getHash(pattern);
    for (int i = 0; i < text.size() - pattern.size() + 1; i++) {
        ll hashDif = hashCodes[i + pattern.size() - 1];
        if (i != 0) {
            hashDif -= hashCodes[i - 1];
        }
        if (hashDif < 0) {
            hashDif += MOD;
        }
        if (i != 0) {
            smallHash = (smallHash * PRIME) % MOD;
        }
        if (smallHash == hashDif) {
            for (int j = i; j < i + pattern.size(); j++){
                vec[j]++;
            }
        }
    }
}

int main() {
    string text; cin >> text;
    vector<size_t> vec(text.size(), 0);
    int n; cin >> n;
    for (int i = 0; i < n; i++) {
        string pattern; cin >> pattern;
        rabinKarp(text, pattern, vec);
    }

    for (int i = 0; i < vec.size(); i++) {
        if (vec[i] == 0) {
            cout << "NO"; return 0;
        }
    }
    cout << "YES";

    return 0;
}