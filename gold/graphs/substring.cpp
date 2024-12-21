#include <bits/stdc++.h>
using namespace std;

const int MAXN = 3*(1e5);
vector<int> graph[MAXN];
int indeg[MAXN];
char val[MAXN];

int main(){
    int n, m; cin >> n >> m;
    for(int i = 0; i < n; i++){
        cin >> val[i];
    }

    for(int i = 0; i < m; i++){
        int a, b; cin >> a >> b;
        a--, b--;
        graph[a].push_back(b);
        indeg[b]++;
    }

    queue<int> q;
    vector<vector<int>> dp(n, vector<int>(26, 0));
    for(int i = 0; i < n; i++){
        dp[i][val[i]-'a']++;
        if(indeg[i] == 0) q.push(i);
    }

    int cnt = 0;
    while(cnt < n && !q.empty()){
        int v = q.front(); q.pop();
        for(auto u : graph[v]){
            for(int i = 0; i < 26; i++){
                if(val[u]-'a' == i)
                    dp[u][i] = max(dp[u][i], dp[v][i]+1);
                else dp[u][i] = max(dp[u][i], dp[v][i]);
            }
            if(--indeg[u] == 0) q.push(u);
        }
        cnt++;
    }

    if(cnt < n){
        cout << -1 << endl;
        return 0;
    }

    int ans = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < 26; j++){
            ans = max(ans, dp[i][j]);
        }
    }
    cout << ans << endl;
}