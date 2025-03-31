#include <bits/stdc++.h>
using namespace std;

const int MAXL = 20;
const int MAXN = 2*(1e5)+7;
vector<int> graph[MAXN];
int depth[MAXN], up[MAXN][MAXL];

void dfs(int v, int p){
    up[v][0] = p;
    depth[v] = depth[p]+1; 
    for(int i = 1; i < MAXL; i++){
        up[v][i] = up[up[v][i-1]][i-1];
    }
    for(auto u : graph[v]){
        if(u != p) dfs(u, v); 
    }
}

int lca(int a, int b){
    if(depth[a] < depth[b]) swap(a, b);
    int k = depth[a] - depth[b];
    for(int i = MAXL-1; i >= 0; i--){
        if(k&(1<<i)){
            a = up[a][i];
        }
    }

    if(a == b) return a; 

    for(int i = MAXL-1; i >= 0; i--){
        if(up[a][i] != up[b][i]){
            a = up[a][i];
            b = up[b][i];
        }
    }

    return up[a][0];
}


int main(){
    int n, q; cin >> n >> q;
    for(int i = 2; i <= n; i++){
        int x; cin >> x;
        graph[x].push_back(i);
    }

    depth[1] = -1;
    dfs(1, 0);
    while(q--){
        int a, b; cin >> a >> b;
        int lowest = lca(a, b);
        cout << lowest << endl;
    }
}