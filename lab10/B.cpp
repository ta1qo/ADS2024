#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int bfs(vector<vector<int>> a, int start, int end) {
    int n = a.size();
    vector<int> visited(n, false);
    vector<int> distance(n, -1);
    queue<int> q;

    visited[start] = true;
    distance[start] = 0;
    q.push(start);
    

    while (!q.empty()) {
        int currentVertex = q.front();
        q.pop();

        for (int neighbor = 0; neighbor < n; neighbor++) {
            if (a[currentVertex][neighbor] == 1 && visited[neighbor] == false) {
                visited[neighbor] = true;
                q.push(neighbor);
                distance[neighbor] = distance[currentVertex] + 1;                
            }
        }

        if (distance[end] != -1) {
            return distance[end];
        }
    }

    return -1;
}

int main() {
    int n; cin >> n;
    vector<vector<int>> v; 
    for (int i = 0; i < n; i++) {
        vector<int> tempRow;
        for (int j = 0; j < n; j++) {
            int temp;
            cin >> temp;
            tempRow.push_back(temp);
        }
        v.push_back(tempRow);
    }

    int start, end; cin >> start >> end;
    cout << bfs(v, start - 1, end - 1);

    return 0;
}