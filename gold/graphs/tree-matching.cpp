#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(0); cin.tie(0)
#define int long long
#define endl "\n"

const int MAXN = 2e5+7;
vector<int> graph[MAXN];
int e[MAXN], ne[MAXN];

void dfs(int v, int p){
    for(auto u : graph[v]){
        if(u == p) continue;
        dfs(u, v);
        ne[v] += max(ne[u], e[u]);
    }

    for(auto u : graph[v]){
        if(u == p) continue;
        e[v] = max(e[v], ne[u] + 1 + ne[v] - max(e[u], ne[u]));
    }
}

signed main(){
    int n; cin >> n;
    for(int i = 0; i < n-1; i++){
        int a, b; cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    dfs(1, 0);
    // cout << " ";
    // for(int i = 1; i <= n; i++){
    //     cout << i << " ";
    // }
    // cout << endl;
    // cout << "a: ";
    // for(int i = 1; i <= n; i++){
    //     cout << e[i] << " ";
    // }
    // cout << endl;
    // cout << "ne: ";
    // for(int i = 1; i <= n; i++){
    //     cout << ne[i] << " ";
    // }
    // cout << endl;

    cout << max(e[1], ne[1]) << endl;
}