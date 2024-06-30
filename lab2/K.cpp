#include<iostream>
#include<queue>
#include<unordered_map>

using  namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;
        queue<char> stream;
        unordered_map<char, int> freq;
        
        for (int i = 0; i < n; i++) {
            char c;
            cin >> c;
            stream.push(c);
            freq[c]++;

            while (!stream.empty() && freq[stream.front()] > 1) {
                stream.pop();
            }

            if (stream.empty()) {
                cout << "-1 ";
            } else {
                cout << stream.front() << ' ';
            }
        }
        cout << '\n';
    }

    return 0;
}