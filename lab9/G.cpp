#include <iostream>
#include <vector>
using namespace std;

void LPS(string &pat, vector<int> &lps) {
    int len = 0;
    int i = 1;
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

int KMP(string &pat) {
    int n = pat.length();
    vector<int> lps(n, 0);
    LPS(pat, lps);
    
    return lps[n - 1];
}

int main() {
    string s; cin >> s;
    cout << s.length() - KMP(s);

    return 0;
}