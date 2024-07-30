#include <bits/stdc++.h>
using namespace std;
 
#define ll long long
#define fastio ios_base::sync_with_stdio(0); cin.tie(0)
#define int long long
 
const ll MAXN = 101;
const ll INF = 1e10;
const ll MAXM = 1e4+1;
ll n, m, s, t;
vector<int> conn [MAXN];
vector<pair<ll, ll>> ar;
vector<ll> w;
vector<ll> profit (MAXN), cost(MAXM), d (MAXN, INF), visited(MAXN);
 
void dfs(int v, vector<int>& vis){
   vis[v] = 1;
   for(auto u : conn[v]) if(!vis[u]) dfs(u, vis);
}


bool bellman(int a){
    d[a] = 0;
    for(int i = 0; i <= n; i++){
        for(int j = 0; j < m; j++){
            if(d[ar[j].second] > d[ar[j].first] + w[j]){
                if (i == n){
                    vector<int> vis(n, 0);
                    dfs(ar[j].second, vis);
                    if(vis[n-1]) return true;
                }
                d[ar[j].second] = d[ar[j].first] + w[j];
            }
        }
    }
 
    return 0;
}

signed main(){
    fastio;
    cin >> n >> m >> s >> t;
    for(int i = 0; i < m; i++){
        int a, b, c;
        cin >> a >> b >> c;
        conn[a].push_back(b);
        ar.push_back({a, b});
        cost[i] = c;
    }
 
    for(int i = 1; i <= n; i++) cin >> profit[i];
 
    for (int i = 0; i <= m; i++){
        w.push_back(cost[i] - profit[ar[i].second]);
    }
 
    dfs(s, visited);
    if(!visited[n-1]){
        cout << "Bad trip" << '\n';
    }
    else if (bellman(s)){
        cout << "Money hack!" << '\n';
    }
    else cout << -1ll*d[t] << '\n';
}