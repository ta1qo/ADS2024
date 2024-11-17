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

void KMP(string &txt, string &pat) {
    int n = txt.length();
    int m = pat.length();

    vector<int> lps(m, 0);
    LPS(pat, lps);

    int i = 0;
    int j = 0;  
    
    while (i < n) {
        if (txt[i] == pat[j]) {
            i++;
            j++;
        } else if (j != 0) {
            j = lps[j - 1];
        } else {
            i++;
        }

        if (j == m) {
            cout << i - j << " ";
            j = lps[j - 1];
        }
    }
}

int main() {
    string txt, pat;
    cin >> txt >> pat;
    KMP(txt, pat);

    return 0;
}