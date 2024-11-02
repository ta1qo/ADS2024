#include <iostream>
#include <vector>
#include <unordered_map>
#define ll long long
using namespace std;

const ll MOD = 1e15 + 9;
const ll PRIME = 31;

long long countOfSubstrings(string s) {
    unordered_map<ll, bool> hashCodes;
    for (ll i = 0; i < s.size(); i++) {
        ll hash = 0;
        for (ll j = i; j < s.size(); j++) {
            hash = (PRIME * hash + s[j]) % MOD;
            if (hashCodes.find(hash) == hashCodes.end()) {
                hashCodes[hash] = true;
            }
        }
    }
    return hashCodes.size();
}


int main() {
    string s;
    cin >> s;
    cout << countOfSubstrings(s);
    return 0;
}