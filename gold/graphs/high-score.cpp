#include <bits/stdc++.h>
using namespace std;

int n, m;

#define ll long long

const ll INF = 1e18;
vector<tuple<int, int, ll>> ar;
vector<ll> d;
vector<vector<int>> adj; 

void dfs(int v, vector<bool>& visited) {
    visited[v] = true;
    for (int u : adj[v]) {
        if (!visited[u]) dfs(u, visited);
    }
}

bool bellman(int a) {
    d.assign(n, -INF);
    d[a] = 0;
    vector<int> parent(n, -1);
    
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            int u, v;
            ll w;
            tie(u, v, w) = ar[j];
            if(d[u] != -INF && d[v] < d[u] + w) {
                d[v] = d[u] + w;
                parent[v] = u;
                if (i == n-1) {
                    vector<bool> visited(n, false);
                    dfs(v, visited);
                    if (visited[n-1]) return true;
                }
            }
        }
    }
    return false;
}

int main() {
    cin >> n >> m;
    ar.resize(m);
    d.resize(n, -INF);
    adj.resize(n);

    for(int i = 0; i < m; i++) {
        int a, b;
        ll c;
        cin >> a >> b >> c;
        a--, b--;
        ar[i] = {a, b, c};
        adj[a].push_back(b); 
    }

    if(bellman(0)) {
        cout << -1 << endl; 
    } else {
        cout << d[n-1] << endl; 
    }
}
