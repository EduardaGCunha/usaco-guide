#include <bits/stdc++.h>
using namespace std;

const int MAXL = 20;
const int MAXN = 2*(1e5)+7;
vector<pair<int, int>> graph[MAXN];
int depth[MAXN], dist[MAXN];
int anc[MAXN][MAXL];

void dfs(int v, int p, int w) {
    dist[v] = dist[p] + w;
    depth[v] = depth[p] + 1;
    anc[v][0] = p;
    for (int i = 1; i < MAXL; i++) {
        anc[v][i] = anc[anc[v][i-1]][i-1];
    }

    for (auto [u, w] : graph[v]) {
        if (u != p) {
            dfs(u, v, w);
        }
    }
}

int lca(int a, int b) {
    if (depth[a] < depth[b]) swap(a, b);
    int k = depth[a] - depth[b];
    for (int i = MAXL-1; i >= 0; i--) {
        if (k & (1 << i)) {
            a = anc[a][i];
        }
    }

    if (a == b) return a;

    for (int i = MAXL-1; i >= 0; i--) {
        if (anc[a][i] != anc[b][i]) {
            a = anc[a][i];
            b = anc[b][i];
        }
    }

    return anc[a][0];
}

int get_kth_ancestor(int u, int k) {
    for (int i = MAXL-1; i >= 0; i--) {
        if (k & (1 << i)) {
            u = anc[u][i];
        }
    }
    return u;
}

int main() {
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        for (int i = 0; i < n; i++) {
            graph[i].clear();
            depth[i] = 0;
            dist[i] = 0;
            memset(anc[i], 0, sizeof(anc[i]));
        }
        for (int i = 0; i < n-1; i++) {
            int a, b, c; cin >> a >> b >> c;
            graph[a].push_back({b, c});
            graph[b].push_back({a, c});
        }
        
        dfs(1, 1, 0);
        string s;
        while (cin >> s && s != "DONE") {
            if (s == "DIST") {
                int a, b; cin >> a >> b;
                int mac = lca(a, b);
                cout << dist[a] + dist[b] - 2 * dist[mac] << endl;
            } else {
                int a, b, c; cin >> a >> b >> c;
                int l = lca(a, b);
                int du = depth[a] - depth[l];
                int dv = depth[b] - depth[l];
                if (c <= du + 1) {
                    int steps = c - 1;
                    int node = get_kth_ancestor(a, steps);
                    cout << node << endl;
                } else {
                    int m = c - (du + 1);
                    int steps = dv - m;
                    int node = get_kth_ancestor(b, steps);
                    cout << node << endl;
                }
            }
        }
        cout << endl;
    }
}