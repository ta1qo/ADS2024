#include <iostream>
#include <vector>
#include <queue>
using namespace std;

void bfs(vector<vector<int>> v, queue<pair<int, int>> q, int n, int m, int mushrooms, int marios) {
    vector<vector<bool>> visited(n, vector<bool>(m, false));
    visited[q.front().first][q.front().second] = true;
    int cnt = 0;
    while (!q.empty()) {
        int tmp = 0;
        bool flag = false;
        while(marios--) {
            int i = q.front().first;
            int j = q.front().second;
            q.pop();

            if (i - 1 >= 0 && v[i - 1][j] == 1 && visited[i - 1][j] == false) {
                flag = true;
                visited[i - 1][j] = true;
                q.push(make_pair(i - 1, j));
                tmp++;
                mushrooms--;
            }
            if (j - 1 >= 0 && v[i][j - 1] == 1 && visited[i][j - 1] == false) {
                flag = true;
                visited[i][j - 1] = true;
                q.push(make_pair(i, j - 1));
                tmp++;
                mushrooms--;
            }
            if (i + 1 < n && v[i + 1][j] == 1 && visited[i + 1][j] == false) {
                flag = true;
                visited[i + 1][j] = true;
                q.push(make_pair(i + 1, j));
                tmp++;
                mushrooms--;
            }
            if (j + 1 < m && v[i][j + 1] == 1 && visited[i][j + 1] == false) {
                flag = true;
                visited[i][j + 1] = true;
                q.push(make_pair(i, j + 1));
                tmp++;
                mushrooms--;
            }
        }

        if (flag) cnt++;

        marios = tmp;
    }

    if (mushrooms == 0) cout << cnt;
    else cout << -1;
}

int main() {
    int n, m; cin >> n >> m;
    vector<vector<int>> v(n, vector<int>(m));
    queue<pair<int, int>> q;
    int mushrooms = 0, marios = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> v[i][j];
            if (v[i][j] == 1) {
                mushrooms++;
            }
            if (v[i][j] == 2) {
                q.push(make_pair(i, j));
                marios++;
            }
        }
    }

    if (mushrooms == 0) {
        cout << 0;
        return 0;
    }

    bfs (v, q, n, m, mushrooms, marios);
    
    return 0;
}