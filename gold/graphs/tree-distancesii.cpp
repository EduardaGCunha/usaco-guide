#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(0); cin.tie(0)
#define int long long
#define endl "\n"


const int MAXN = 2e5+7;
vector<int> graph[MAXN];
int depth[MAXN], ans[MAXN], sz[MAXN];

int n;

void dfs(int v, int p){
    sz[v] = 1;
    depth[v] = depth[p] + 1;
    for(auto u : graph[v]){
        if(u == p) continue;
        dfs(u, v);
        sz[v] += sz[u];
    }
}

void dfs2(int v, int p){
    for(auto u : graph[v]){
        if(u == p) continue;
        ans[u] = ans[v] - sz[u] + (n - sz[u]);
        dfs2(u, v);
    }
}

signed main(){
    fastio;
    cin >> n;
    for(int i = 0; i < n-1; i++){
        int a, b; cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    depth[0] = -1;
    dfs(1, 0);

    // for(int i = 2; i <= n; i++){
    //     cout << depth[i] << " ";
    // }
    // cout << endl;
    for(int i = 2; i <= n; i++) ans[1] += depth[i];
    // cout << ans[1] << endl;
    dfs2(1, 0);
    for(int i = 1; i <= n; i++) cout << ans[i] << " ";
    cout << endl;
}