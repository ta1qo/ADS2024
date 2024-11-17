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

bool KMP(string &txt, string &pat) {
    int n = txt.length();
    int m = pat.length();

    vector<int> lps(m, 0);
    vector<int> res;
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
            return true;
        }
    }

    return false;
}

int main() {
    string A, B;
    cin >> A >> B;
    // 1
    if (A == B) {
        cout << 1;
        return 0;
    }
    // 2
    int cnt = 1;
    string tmp = A;
    while (tmp.length() < B.length()) {
        tmp += A;
        cnt++;
    }

    if (KMP(tmp, B)) {
        cout << cnt;
        return 0;
    }
    // 3
    tmp += A; 
    cnt++;

    if (KMP(tmp, B)) {
        cout << cnt;
        return 0;
    }

    cout << -1;

    return 0;
}