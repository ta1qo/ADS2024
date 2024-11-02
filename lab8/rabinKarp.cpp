#include <iostream>
#include <vector>
#define ll long long
using namespace std;
// Rabin-Karp Algorithm for Pattern Searching
const ll MOD = 1e9 + 7;
const ll PRIME = 31;

ll getHash(string& text) {
    ll hash = 0, power = 1;
    for (int i = 0; i < text.size(); i++) {
        hash = (hash + (text[i] - 'a' + 1) * power) % MOD;
        power = (power * PRIME) % MOD;
    }
    return hash;
}

vector<ll> getPrefixHashes(string& text) {
    vector<ll> hashCodes(text.size()); 
    ll hash = 0, power = 1;
    for (int i = 0; i < text.size(); i++) {
        hash = (hash + (text[i] - 'a' + 1) * power) % MOD;
        hashCodes[i] = hash;
        power = (power * PRIME) % MOD;
    }
    return hashCodes;
}

vector<int> rabinKarp(string& text, string& pattern) {
    vector<ll> hashCodes = getPrefixHashes(text); 
    vector<int> occurrences;
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
            occurrences.push_back(i);
        }
    }
    return occurrences;
}


int main() {
    string text, pattern;
    cin >> text >> pattern;
    cout << "\nhash of '" << pattern << "' is " << getHash(pattern);

    cout << "\nhashes of all prefixes:\t";
    vector<ll> prefixHashes = getPrefixHashes(text);
    for (int i = 0; i < prefixHashes.size(); i++) {
        cout << prefixHashes[i] << " ";
    }
    cout << "\n";
    vector<int> occurrences = rabinKarp(text, pattern);
    if (occurrences.empty()) cout << "does not occur :(";
    else cout << "occurs at: ";
    for (int i = 0; i < occurrences.size(); i++) {
        cout <<occurrences[i] << " ";
    }

    return 0;
}