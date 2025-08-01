#include <bits/stdc++.h>
using namespace std;

void dfs(int u, const vector<vector<int>>& adj, vector<bool>& vis) {
    vis[u] = true;
    for (int v : adj[u]) {
        if (!vis[v]) dfs(v, adj, vis);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // --- INPUT ---
    // First line: two ints n (number of vertices) and m (number of edges)
    // Then m lines of edges u v (0-based or 1-based—you can adjust).
    //
    // For your specific graph you can do:
    //   n = 12, m = 16
    //   edges as listed in the problem statement.
    //
    int n, m;
    cin >> n >> m;

    vector<vector<int>> adj(n);
    vector<int> deg(n, 0);

    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        // if input is 1-based, uncomment:
        // --u; --v;
        adj[u].push_back(v);
        adj[v].push_back(u);
        deg[u]++; deg[v]++;
    }

    // --- 1) Find a vertex with non-zero degree to start DFS ---
    int start = -1;
    for (int i = 0; i < n; i++) {
        if (deg[i] > 0) {
            start = i;
            break;
        }
    }
    // If there are no edges in the graph at all, it's trivially Eulerian.
    if (start == -1) {
        cout << "YES\n";
        return 0;
    }

    // --- 2) Check connectivity among non-isolated vertices ---
    vector<bool> vis(n, false);
    dfs(start, adj, vis);
    for (int i = 0; i < n; i++) {
        if (deg[i] > 0 && !vis[i]) {
            cout << "NO\n";   // disconnected
            return 0;
        }
    }

    // --- 3) Check that every vertex has even degree ---
    for (int i = 0; i < n; i++) {
        if (deg[i] % 2 != 0) {
            cout << "NO\n";
            return 0;
        }
    }

    // If we reach here, both conditions hold:
    cout << "YES\n";
    return 0;
}
