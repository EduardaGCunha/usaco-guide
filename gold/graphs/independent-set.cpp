#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(0); cin.tie(0)
#define int long long
#define endl "\n"

const int MOD = 1e9+7;
const int MAXN = 1e5+7;
vector<int> graph[MAXN];
int branco[MAXN], preto[MAXN];

void dfs(int v, int p){
    branco[v] = 1;
    preto[v] = 1;
    for(auto u : graph[v]){
        if(u == p) continue;
        dfs(u, v);
        branco[v] = (branco[v]*(branco[u] + preto[u]))%MOD;
        preto[v] = (preto[v]*(branco[u]))%MOD;
    }
}

signed main(){
    fastio;
    int n; cin >> n;
    for(int i = 0; i < n-1; i++){
        int a, b; cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    dfs(1, 0);

    cout << (branco[1] + preto[1])%MOD << endl;
}