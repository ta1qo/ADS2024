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

int main() {
    string s;
    cin >> s; 

    vector<int> lps(s.size(), 0);
    LPS(s, lps);

    int cnt = 0;
    for (int i = 1; i < lps.size(); i++) {
        if (i % 2 == 0) {
            int k = i - lps[i - 1];
            if ((i / k) % 2 == 0) {
                cnt++;
            }
        }
    }

    cout << cnt;

    return 0;
}