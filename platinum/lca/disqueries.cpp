#include <bits/stdc++.h>
using namespace std; 

#define fastio ios_base::sync_with_stdio(0); cin.tie(0)
#define endl "\n"

const int MAXN = 5*(1e5)+7;
const int MAXL = 20;
vector<pair<int, int>> graph[MAXN];
int depth[MAXN];
int anc[MAXN][MAXL], mx[MAXN][MAXL], mn[MAXN][MAXL];

void dfs(int v, int p, int k){
    depth[v] = depth[p]+1;
    anc[v][0] = p;
    mx[v][0] = k;
    mn[v][0] = k;
    for(int i = 1; i < MAXL; i++){
        anc[v][i] = anc[anc[v][i-1]][i-1];
        mx[v][i] = max(mx[v][i-1], mx[anc[v][i-1]][i-1]);
        mn[v][i] = min(mn[v][i-1], mn[anc[v][i-1]][i-1]);
    }

    for(auto [u, w] : graph[v]) if(u != p) dfs(u, v, w);
    
}

pair<int, int> lca(int a, int b){
    if(depth[a] < depth[b]) swap(a, b);
    int k = depth[a] - depth[b];
    int maxval = INT_MIN, minval = INT_MAX;
    for(int i = MAXL-1; i>= 0; i--){
        if(k&(1<<i)){
            maxval = max(maxval, mx[a][i]);
            minval = min(minval, mn[a][i]);
            a = anc[a][i];
        }
    }

    if(a == b) return {minval, maxval};

    for(int i = MAXL-1; i >= 0; i--){
        if(anc[a][i] != anc[b][i]){
            maxval = max({maxval, mx[a][i], mx[b][i]});
            minval = min({minval, mn[a][i], mn[b][i]});
            a = anc[a][i];
            b = anc[b][i];
        }
    }
    maxval = max({maxval, mx[a][0], mx[b][0]});
    minval = min({minval, mn[a][0], mn[b][0]});
    return {minval, maxval};
}

int main(){
    fastio;
    int n; cin >> n;
    for(int i = 0; i < n-1; i++){
        int a, b, c; cin >> a >> b >> c;
        graph[a].push_back({b, c});
        graph[b].push_back({a, c});
    }
    dfs(1, 0, 0);
    int q; cin >> q;
    while(q--){
        int a, b; cin >> a >> b;
        pair<int, int> p = lca(a, b);
        cout << p.first << " " << p.second << endl;
    }
}