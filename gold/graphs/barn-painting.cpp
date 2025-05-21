#include <bits/stdc++.h>
using namespace std;


#define fastio ios_base::sync_with_stdio(0); cin.tie(0)
#define int long long
#define endl "\n"

const int MOD = 1e9+7;
const int MAXN = 1e5+7;
vector<int> graph[MAXN];
int cor[MAXN][3], cores[MAXN];

void dfs(int v, int p){
    for(auto u : graph[v]){
        if(u == p) continue;
        dfs(u, v);
        cor[v][0] = (cor[v][0]*(cor[u][1] + cor[u][2]))%MOD;
        cor[v][1] = (cor[v][1]*(cor[u][0] + cor[u][2]))%MOD;
        cor[v][2] = (cor[v][2]*(cor[u][0] + cor[u][1]))%MOD;
    }
}

signed main(){
    freopen("barnpainting.in", "r", stdin);
    freopen("barnpainting.out", "w", stdout);
    int n, k; cin >> n >> k;
    for(int i = 0; i < n-1; i++){
        int a, b; cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    for(int i = 1; i <= n; i++){
        cor[i][0] = 1;
        cor[i][1] = 1;
        cor[i][2] = 1;
    }

    for(int i = 0; i < k; i++){
        int u, c; cin >> u >> c;
        cor[u][(c+1)%3] = 0;
        cor[u][(c+2)%3] = 0;
    } 

    dfs(1, 0);

    cout << (cor[1][0] + cor[1][1] + cor[1][2])%MOD << endl;

}