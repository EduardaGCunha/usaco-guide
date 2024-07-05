#include <bits/stdc++.h>
using namespace std;

const int MAXN = 5*(1e3)+7;
vector<pair<int, int>> graph[MAXN];
int visited[MAXN];
int k, cnt;

void dfs(int v){
    visited[v] = 1;
    for(auto u : graph[v]){
        if(!visited[u.first] && u.second >= k){
            cnt++;
            dfs(u.first);
        }
    }
}

int main(){
    freopen("mootube.in", "r", stdin);
    freopen("mootube.out", "w", stdout);
    int n, m; cin >> n >> m;
    for(int i = 0; i < n-1; i++){
        int a, b, c; cin >> a >> b >> c;
        a--, b--;
        graph[a].push_back({b,c});
        graph[b].push_back({a, c});
    }

    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++) visited[j] = 0;
        int a; cin >> k >> a;
        a--;
        cnt = 0;
        dfs(a);
        cout << cnt << endl;
    }
}