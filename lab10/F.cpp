#include <iostream>
#include <vector>
#include <queue>
using namespace std;

bool bfsAdjList(vector<vector<int>> a, int v1, int v2) {
    vector<bool> visited(a.size(), false);
    queue<int> q;

    visited[v1] = true;
    q.push(v1);

    while (!q.empty()) {
        int currentVertex = q.front();
        q.pop();

        if (currentVertex == v2) {
            return true;
        }

        for (int neighbor : a[currentVertex]) {
            if (!visited[neighbor]) {
                visited[neighbor] = true;
                q.push(neighbor);
            }
        }
    }

    return false;
}


int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> a(n);
    vector<int> visited(n, 0);

    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;

        a[x-1].push_back(y-1);
        a[y-1].push_back(x-1);
    }

    int s, f;
    cin >> s >> f;

    if (bfsAdjList(a, s - 1, f - 1)) {
        cout << "YES";
    } else {
        cout << "NO";
    }

    return 0;
}