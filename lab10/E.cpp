#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n, q; cin >> n >> q;
    vector <vector <int> > adj(n, vector<int> (n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> adj[i][j];
        }
    }
    while (q--) {
        int a, b, c; cin >> a >> b >> c;
        if (adj[a - 1][b - 1] == 1 && adj[a - 1][c - 1] && adj[b - 1][c - 1])
            cout << "YES\n";
        else
            cout << "NO\n";
    }

    return 0;
    }