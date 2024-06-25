#include<iostream>
#include<string>
#include<stack>
using namespace std;

string isBalanced(const string S) {
    stack<char> st;

    for (char c : S) {
        if (!st.empty() && st.top() == c) {
            st.pop();
        } else {
            st.push(c);
        }
    }

    return st.empty() ? "YES" : "NO";
}

int main() {
    string s;
    cin >> s;
    cout << isBalanced(s);

    return 0;
}