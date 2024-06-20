#include <bits/stdc++.h>
using namespace std;
const int MAXN = 200007;
vector<int> graph[MAXN];
int dist_dp[MAXN];

int dfs(int v, int p){
    if(dist_dp[v] != 0) return dist_dp[v];
    int ans = 0;
    for(auto a : graph[v]){
        if(a == p) continue;
        ans = max(ans, dfs(a, v)+1);
    }
    return ans;
}

int main(){
    int n; cin >> n;
    for(int i =0; i < n -1; i++){
        int a, b; cin >> a >> b;
        a--, b--;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    cout << dfs(0, -1)+1 << endl;
}
