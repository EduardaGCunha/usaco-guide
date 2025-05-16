#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(0); cin.tie(0)
#define int long long
#define endl "\n"

const int MAXL = 30;
const int MAXN = 2*(1e5)+7;
vector<int> graph[MAXN];
int visited[MAXN], depth[MAXN];
int anc[MAXN][MAXL];
int mx = 0, lst = 0;

void dfs(int v, int p){
    anc[v][0] = p;
    depth[v] = depth[p] + 1;
    for(int i = 1; i < MAXL; i++){
        anc[v][i] = anc[anc[v][i-1]][i-1];
    }
    for(auto u : graph[v]){
        if(u != p) dfs(u, v);
    }
}

void dfs2(int v, int d){
    //cout << v << " " << d << endl;
    if(d > mx){
        mx = d;
        lst = v;
    }
    visited[v] = 1;
    for(auto u : graph[v]){
        if(!visited[u]) dfs2(u, d + 1);
    }
}

int lca(int a, int b){
    if(depth[a] < depth[b]) swap(a, b);
    int k = depth[a] - depth[b];
    for(int i = MAXL-1; i>= 0; i--){
        if(k&(1<<i)) a = anc[a][i];
    }
    if(a == b) return a;

    for(int i = MAXL-1; i>= 0; i--){
        if(anc[a][i] != anc[b][i]){
            a = anc[a][i];
            b = anc[b][i];
        }
    }
    return anc[a][0];
}

int answer(int a, int b, int k){
    int mac = lca(a, b);
    //cout << a << " " << b << " " << mac << " " << depth[a] + depth[b] - 2*depth[mac] << " " << k << endl;
    if(depth[a] + depth[b] - 2*depth[mac] < k) return -1;
    int du = depth[a] - depth[mac];
    int dv = depth[b] - depth[mac];
    int steps = 0;

    if(k <= du){
        steps = k;
    }else{
        steps = dv - (k - (du));
        a = b;
    }

    for(int i = MAXL-1; i>=0; i--){
        if(steps&(1<<i)){
            a = anc[a][i];
        }
    }
    return a;
}  

signed main(){
    fastio;
    int n; cin >> n;
    for(int i = 0; i < n-1; i++){
        int a, b; cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    dfs(1, 1);
    memset(visited, 0, sizeof(visited));
    dfs2(1, 1);
    int d1 = lst;
    mx = 0, lst = -1;
    memset(visited, 0, sizeof(visited));
    dfs2(d1, 1);
    int d2 = lst; 
    int q; cin >> q;
    //cout << d1 << " " << d2 << endl;
    while(q--){
        int a, k; cin >> a >> k;
        cout << max(answer(a, d1, k), answer(a, d2, k)) << endl;
    

    }
}