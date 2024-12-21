#include <bits/stdc++.h>
using namespace std;

#define int long long

const int MAXN = 1e5+7;
vector<pair<int, int>> graph[MAXN];
int dp[MAXN], indeg[MAXN];

signed main(){
    freopen("timeline.in", "r", stdin);
    freopen("timeline.out", "w", stdout);
    int n, m, c; cin >> n >> m >> c;
    for(int i = 0; i < n; i++){
        cin >> dp[i];
    }

    for(int i = 0; i < c; i++){
        int a, b, k; cin >> a >> b >> k;
        a--, b--;
        indeg[b]++;
        graph[a].push_back({b, k});
    }

    queue<int> q;
    for(int i = 0; i < n; i++){
        if(indeg[i] == 0){
            q.push(i);
           // cout << i << endl;
        }
    }  

    while(!q.empty()){
        auto v = q.front(); q.pop();
        //cout << v << endl;
        for(auto u : graph[v]){
            if(dp[u.first] < dp[v] + u.second && dp[v] + u.second <= m) 
                dp[u.first] = dp[v] + u.second;
            if(--indeg[u.first] == 0) q.push(u.first);
        }
    }

    for(int i = 0; i < n; i++){
        cout << dp[i] << endl;
    }
}