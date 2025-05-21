#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(0); cin.tie(0)
#define int long long
#define endl '\n'

const int MAXN = 1e5+7;
vector<int> graph[MAXN];
int dp[2][MAXN], l[MAXN], r[MAXN];

void dfs(int v, int p){
    dp[1][v] = dp[0][v] = 0;
    for(auto u : graph[v]){
        if(u == p) continue;
        dfs(u, v);
        dp[1][v] += max(dp[0][u] + abs(l[u] - r[v]), dp[1][u] + abs(r[u]-r[v]));
        dp[0][v] += max(dp[0][u] + abs(l[u] - l[v]), dp[1][u] + abs(r[u] - l[v]));
    }
}

signed main(){
    fastio;
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        for(int i = 1; i <= n; i++) graph[i].clear();
        for(int i = 1; i <= n; i++) cin >> l[i] >> r[i];
        for(int i = 1; i < n; i++){
            int a, b; cin >> a >> b;
            graph[a].push_back(b);
            graph[b].push_back(a);
        }
        dfs(1, 1);
        cout << max(dp[1][1], dp[0][1]) << endl; 
    }
}