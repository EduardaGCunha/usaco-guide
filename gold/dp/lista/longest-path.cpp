#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
#define fastio ios_base::sync_with_stdio(0); cin.tie(0)

const int MAXN = 1e5+7;
int indeg[MAXN], dp[MAXN];
vector<int> graph[MAXN];
int main(){
    fastio;
    int n, m; cin >> n >> m;
    for(int i = 0; i < m; i++){
        int a, b; cin >> a >> b;
        indeg[b]++;
        graph[a].push_back(b);
    }

    priority_queue<int> pq;
    for(int i = 1; i <= n; i++){
        if(!indeg[i]){
            pq.push(i);
        }
    }

    while(!pq.empty()){
        int v = pq.top(); pq.pop();
        for(auto u : graph[v]){
            dp[u] = max(dp[u], dp[v] + 1);
            if(--indeg[u] == 0) pq.push(u);
        }
    }

    int ans = 0;
    for(int i = 1; i <= n; i++){
        ans = max(ans, dp[i]);
    }
    cout << ans << endl;
}