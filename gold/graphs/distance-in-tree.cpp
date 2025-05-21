#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(0); cin.tie(0)
#define int long long
#define endl "\n"

const int MAXK = 507;
const int MAXN = 5e4+7;
vector<int> graph[MAXN];
int dp[MAXN][MAXK];

int n, k, ans = 0;

void dfs(int v, int p){
    dp[v][0] = 1;
    for(auto u : graph[v]){
        if(u == p) continue;
        dfs(u, v);
        for(int i = 0; i < k; i++){
            ans += (dp[u][i]*dp[v][k-i-1]);
        }
        for(int i = 0; i < k; i++){
            dp[v][i+1] += dp[u][i];
        }
    }
}

signed main(){
    fastio;
    cin >> n >> k;
    for(int i = 0; i < n-1; i++){
        int a, b; cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    dfs(1, 0);
    cout << ans << endl;
}