#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

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
    vector <pair <int, pair <int,int> > > g;
    for (int i = 0; i < m; i++) {
        int l, r, c; cin >> l >> r >> c;
        g.push_back(make_pair(c, make_pair(--l, --r)));
    }
    int k = g.size();
    long long cost = 0;
    sort(g.begin(), g.end());
    p.resize(n);
    for (int i = 0; i < n; i++)
        p[i] = i;
    for (int i = 0; i < k; i++) {
        int a = g[i].second.first, b = g[i].second.second, l = g[i].first;
        for (int j = a; j < b, a <= b; j++, ++a)
            if (dsu_get(j) != dsu_get(a)) {
                cost += l;
                dsu_unite(j, a);
            }
            else {
                j = p[a];
                a = j;
                j--;
            }
    }
    cout << cost;
}