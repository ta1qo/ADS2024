#include<iostream>
#include<queue>
using namespace std;

int main() {
    int n; 
    cin >> n;
    queue<int> q;
    for (int i = 0; i < n; i++) {
        int x; 
        cin >> x;
        q.push(x);
    }

    int before = INT_MAX;
    while (!q.empty()) {
        if (before < q.front()) {
            cout << before << " ";
        } else {
            cout << -1 << " ";
        }        
        before = q.front();
        q.pop();
    }

    return 0; 
}