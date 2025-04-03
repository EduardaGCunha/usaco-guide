#include <bits/stdc++.h>
using namespace std;


#define fastio ios_base::sync_with_stdio(0); cin.tie(0)
#define endl "\n"

const int MAXL = 20;
const int MAXN = 5*(1e5)+7;
pair<int, int> valores[MAXN];
vector<int> graph[MAXN];
int depth[MAXN];
int anc[MAXN][MAXL];

void dfs(int v, int p){
    depth[v] = depth[p]+1;
    anc[v][0] = p;  
    for(int i = 1; i < MAXL; i++){
        anc[v][i] = anc[anc[v][i-1]][i-1];
    }

    for(auto u : graph[v]){
        if(u != p) dfs(u, v);
    }
} 

int lca(int a, int b){
    if(depth[a] < depth[b]) swap(a, b); 
    int k = depth[a] - depth[b];
    for(int i = MAXL-1; i>= 0; i--){
        if(k&(1<<i)){
            a = anc[a][i];
        }
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

int main(){
    fastio;
    int n; cin >> n;
    for(int i = 1; i <= n; i++){
        int a; cin >> a;
        if(valores[a].first == 0) valores[a].first = i;
        else valores[a].second = i;
    }

    for(int i = 0; i < n-1; i++){
        int a, b; cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    dfs(1, 1);
    int ans = 0;
    for(int i = 1; i <= n/2; i++){
        int a = valores[i].first;
        int b = valores[i].second;
        int mac = lca(a, b);
        ans += depth[a] + depth[b] - 2*depth[mac];
    }
    
    cout << ans << endl;
}