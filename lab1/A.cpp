#include<iostream>
#include<queue>
#include<vector>
using namespace std;

vector<int> rotation(const int n) {
    queue<int> q;
    int arr[1001];
    for (int i = 1; i <= n; i++) {
        q.push(i);
    }

    int i = 1, x;
    while (!q.empty()) {
        int j = 0;
        while (i > j) {
            x = q.front();
            q.pop();
            q.push(x);
            j++;
        }
        x = q.front();
        arr[x] = i;
        q.pop();
        i++;
    }

    vector<int> deck; 
    for (int i = 1; i <= n; i++) {
        deck.push_back(arr[i]);
    }

    return deck;
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n; 
        cin >> n;
        vector<int> deck = rotation(n);
        for (int i : deck) {
            cout << i << ' ';
        }
        cout << endl;
    }

    return 0;
}