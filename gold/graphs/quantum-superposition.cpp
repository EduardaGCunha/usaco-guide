#include <bits/stdc++.h>
using namespace std;

int n[2], m[2];
const int MAXN = 1e4+2;
vector<int> graph[2][MAXN];
int indeg[2][MAXN];
set<int> dp[2][MAXN];

void solve(int x){
    for(int i = 0; i < m[x]; i++){
        int a, b; cin >> a >> b;
        graph[x][a].push_back(b);
        indeg[x][b]++;
    }

    queue<int> q;

    q.push(1);
    dp[x][1].insert(0);

    while(!q.empty()){
        auto v = q.front(); q.pop();
        for(auto u : graph[x][v]){
            for(auto val : dp[x][v]){
                dp[x][u].insert(val+1);
            }
            if(--indeg[x][u] == 0) q.push(u);
        }
    }

}

int main(){
    cin >> n[0] >> n[1] >> m[0] >> m[1];
    solve(0);
    solve(1);

    vector<int> ans(2*MAXN+1, 0);
    for(auto u : dp[0][n[0]]){
        for(auto v : dp[1][n[1]]){
            if(u+v <= 2*MAXN+1) ans[u+v] = 1;
        }
    }


    int q; cin >> q;
    while(q--){
        int x; cin >> x;
        if(ans[x]) cout << "Yes\n";
        else cout << "No\n";
    }
    
}