#include <iostream>
#include <vector>
#include <queue>
using namespace std;

void bfsFindDistOfRed(vector<vector<int>> &data, int vertex, vector<int> &distance) {
    queue<int> q;
    q.push(vertex);
    while (!q.empty()) {
        int curr = q.front();
        q.pop();
        vector<int> neighbours = data[curr];
        for (int i = 0; i < neighbours.size(); i++) {
            int neighbour = neighbours[i];
            if (distance[neighbour] != 0 && distance[curr] + 1 < distance[neighbour]) {
                distance[neighbour] = distance[curr] + 1;
                q.push(neighbour);
            }
        }
    }
}

int main() {
    int n, m, q;
    cin >> n >> m >> q;

    vector<vector<int>> data(n, vector<int>());
    vector<int> distance(n, 1e9);
    for (int i = 0; i < m; i++) {
        int first, second;
        cin >> first >> second;
        if (first == second) continue;
        data[first - 1].push_back(second - 1);
        data[second - 1].push_back(first - 1);
    }

    for (int i = 0; i < q; i++) {
        int type, vertex;
        cin >> type >> vertex;
        if (type == 1) {
            distance[vertex - 1] = 0;
            bfsFindDistOfRed(data, vertex - 1, distance);
        } else {
            if (distance[vertex - 1] == 1e9) {
                cout << -1 << endl;
            } else {
                cout << distance[vertex - 1] << endl;
            };
        }
    }
}