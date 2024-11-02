#include <iostream>
#define ll long long
using namespace std;

int main() {
    int n; cin >> n;
    ll prev = 0, power = 1; 
    string s = "";
    for (int i = 0; i < n; i++) {
        ll cur; cin >> cur; 
        char c = (cur - prev) / power + 97; 
        s += c;
        prev = cur;
        power *= 2;
    }
    
    cout << s;

    return 0;
}