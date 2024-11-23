#include <iostream>
#include <vector>
#include <queue>
using namespace std;

#define N 100000

vector <int> degree(N, 0);
queue <int> quests;

bool bfs(vector<vector<int>> &adj, int n) {
    queue <int> q;
    for (int i = 0; i < n; i++) {
        if (degree[i] == 0) {
            q.push(i);
            quests.push(i);
        }
    }
    while (!q.empty()) {
        int cur = q.front();
        q.pop();
        n--;
        for (int i = 0; i < adj[cur].size(); i++) {
            if (--degree[adj[cur][i]] == 0) {
                q.push(adj[cur][i]);
                quests.push(adj[cur][i]);
            }
        }
    }
    return n == 0;
}

int main() {
    int n, m; cin >> n >> m;
    vector <vector <int> > adj(n);
    while (m--) {
        int a, b; cin >> a >> b;
        adj[a - 1].push_back(b - 1);
        degree[b - 1]++;
    }
    if (!bfs(adj, n))
        cout << "Impossible";
    else {
        cout << "Possible\n";
        while(!quests.empty()) {
            cout << quests.front() + 1 << ' ';
            quests.pop();
        }
    }
}