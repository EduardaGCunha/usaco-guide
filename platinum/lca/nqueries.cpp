#include <bits/stdc++.h>
using namespace std; 

#define fastio ios_base::sync_with_stdio(0); cin.tie(0)
#define endl "\n"

const int MAXN = 5*(1e5)+7;
const int MAXL = 20;
vector<pair<int, int>> graph[MAXN];
int depth[MAXN];
int anc[MAXN][MAXL], ans[MAXN][MAXL];

void dfs(int v, int p, int w){
    depth[v] = depth[p]+1;
    anc[v][0] = p;
    ans[v][0] = w;
    for(int i = 1; i < MAXL; i++){
        anc[v][i] = anc[anc[v][i-1]][i-1];
        ans[v][i] = max(ans[v][i-1], ans[anc[v][i-1]][i-1]);
    }

    for(auto [u, w] : graph[v]) if(u != p) dfs(u, v, w);
    
}

int lca(int a, int b){
    if(depth[a] < depth[b]) swap(a, b);
    int k = depth[a] - depth[b];
    int res = 0;
    for(int i = MAXL-1; i>= 0; i--){
        if(k&(1<<i)){
            res = max(res, ans[a][i]);
            a = anc[a][i];
        }
    }

    if(a == b) return res;

    for(int i = MAXL-1; i >= 0; i--){
        if(anc[a][i] != anc[b][i]){
            res = max({res, ans[a][i], ans[b][i]});
            a = anc[a][i];
            b = anc[b][i];
        }
    }
    return max({res, ans[a][0], ans[b][0]});
}

int main(){
    fastio;
    int n;
    while(cin >> n && n){
        memset(depth, 0, sizeof(depth));
        memset(ans, 0, sizeof(ans));
        memset(anc, 0, sizeof(anc));
        for(int i = 1; i <= n; i++) graph[i].clear();
        for(int i = 0; i < n-1; i++){
            int a, b, c; cin >> a >> b >> c;
            graph[a].push_back({b, c});
            graph[b].push_back({a, c});
            //ans[b][0] = c;
        }
        dfs(1, 0, 0);
        int q; cin >> q;
        while(q--){
            int a, b; cin >> a >> b;
            cout << lca(a, b) << endl;
        }
        cout << endl;
    }
}