#include <iostream>
#include <vector>
#include <map>
#include <queue>
using namespace std;

int bfs(vector<vector<int>>& adjList, int start, int n, vector<int>& visited) {
    queue<int> q;
    q.push(start);
    vector<int> childred(n, 0);
    map<int, int> parents;

    for (int i = 0; i < n; i++) {
        parents[i] = -1;
    }

    int cnt = 0;

    while (!q.empty()) { 
        int current = q.front();
        q.pop();
        visited[current] = true;
        for (int neighbor : adjList[current]) {
            if (parents[neighbor] == -1) {
                q.push(neighbor);
                parents[neighbor] = current;
                childred[current]++;
            }
        }

        if (parents[current] == -1 || childred[current] > childred[parents[current]]) {
            cnt++;
        }
    }

    return cnt;
}

int main(){
    int n, m;
    cin >> n >> m;
    vector<vector<int>> adjList(n);

    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;

        adjList[x-1].push_back(y-1);
    }

    int cnt = 0;
    vector<int> visited(n, false);
    for (int i = 0; i < n; i++) {
        if (!visited[i]) cnt += bfs(adjList, i, n, visited);
    }

    cout << cnt << endl;
}