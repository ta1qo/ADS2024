#include <iostream>
#include <vector>
#include <stack>

using namespace std;

vector <vector <int> > g(200000);
vector<int> p (200000);

int dsu_get (int v) {
	return (v == p[v]) ? v : (p[v] = dsu_get (p[v]));
}

void dsu_unite (int a, int b) {
	a = dsu_get (a);
	b = dsu_get (b);

	if (a != b)
		p[a] = b;
}

int main() {
    int n, m; cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int v, u; cin >> v >> u ;
        if (v > u)
            swap(v, u);
        g[--v].push_back(--u);
    }
    for (int i = 0; i < n; i++)
        p[i] = i;
    int cnt = 0;
    stack <int> ans;
    ans.push(0);
    for (int i = n - 1; i >= 0; i--) {
        bool ok = false;
        for (int j = 0; j < g[i].size(); j++) {
            int b = g[i][j];
            if (dsu_get(i) != dsu_get(b)) {
                ok = true;
                int old_p = dsu_get(i);
                dsu_unite(i, b);
                if (old_p != dsu_get(i) && old_p != i)
                    cnt--;
            }
        }
        if (!ok)
            cnt++;
        ans.push(cnt);
    }
    ans.pop();
    while(!ans.empty()) {
        cout << ans.top() << '\n';
        ans.pop();
    }
}