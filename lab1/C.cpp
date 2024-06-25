#include<iostream>
#include<string>
#include<stack>
using namespace std;

stack<char> string_to_stack(const string s) {
    stack<char> st;
    for (char c : s) {
        if (c == '#' && !st.empty()) {
            st.pop();
        } else if (c != '#') {
            st.push(c);
        }
    }

    return st;
}

bool isEqual(stack<char> st1, stack<char> st2) {
    while (!st1.empty() && !st2.empty()) {
        if (st1.top() != st2.top()) {
            return false;
        }
        st1.pop();
        st2.pop();
    }

    return st1.empty() && st2.empty();
}

int main() {
    string s1, s2;
    cin >> s1 >> s2;

    stack<char> st1 = string_to_stack(s1);
    stack<char> st2 = string_to_stack(s2);

    cout << (isEqual(st1, st2) ? "Yes" : "No");

    return 0;
}