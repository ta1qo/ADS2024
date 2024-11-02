#include <iostream>
#include <string>
#include <map>
#include <vector>
#define ll long long
using namespace std;

const ll MOD = 1e9 + 7;
const ll PRIME = 11;

string getHash(string s) {
    ll hash = 0, power = 1;
    for (int i = 0; i < s.size(); i++) {
        hash = (hash + (s[i] - 47) * power) % MOD;
        power = (power * PRIME) % MOD;
    }
    return to_string(hash);
}

int main() {
    int n; cin >> n;
    vector<string> arr;
    map<string, bool> hashCodes;

    for (int i = 0; i < 2*n; i++) {
        string s; cin >> s;
        arr.push_back(s);
        hashCodes[s] = true;
    }

    int t = 0;
    for (int i = 0; i < 2*n; i++) {
        if (t == n) break;
        string hash = getHash(arr[i]);
        if (hashCodes[hash] == true) {
            cout << "Hash of string " << '"' << arr[i] << '"' <<  " is " << hash << endl;
            t++;
        }
    }

    return 0;
}

