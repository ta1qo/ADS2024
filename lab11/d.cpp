#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> p (1000);

int dsu_get (int v) {
	return (v == p[v]) ? v : (p[v] = dsu_get (p[v]));
}

void dsu_unite (int a, int b) {
	a = dsu_get (a);
	b = dsu_get (b);
	if (rand() & 1)
		swap (a, b);
	if (a != b)
		p[a] = b;
}

int main() {
    int n; cin >> n;
    vector <pair <int, pair <int,int> > > g;
    int vertices[n];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            int a; cin >> a;
            if (j >= i + 1 && j != i) {
                g.push_back(make_pair(a, make_pair(i, j)));
            }
        }
    }
    int m = g.size();
    int cost = 0;
    sort(g.begin(), g.end());
    p.resize(n);
    for (int i = 0; i < n; i++)
        p[i] = i;
    for (int i = 0; i < m; i++) {
        int a = g[i].second.first, b = g[i].second.second, l = g[i].first;
        if (dsu_get(a) != dsu_get(b)) {
            cost += l;
            dsu_unite(a, b);
        }
    }
    cout << cost;
}