#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e5;
vector<int> graph[MAXN];
int n, m;

int bfs(int x){
    vector<int> dist(n, -1);
    queue<pair<int, int>> q;
    q.push({x, -1}); //node, parent;
    dist[x] = 0;

    int ans = INT_MAX;
    while(!q.empty()){
        auto [v, p] = q.front(); q.pop();

        for(auto u : graph[v]){
            if(u == p) continue;
            if(dist[u] == -1){
                dist[u] = dist[v] + 1;
                q.push({u, v});
            }else{
                ans = min(ans, dist[u]+dist[v]+1);
            }
        }
    }

    return ans;
}

int main(){
    cin >> n >> m;
    for(int i = 0; i < m; i++){
        int a, b; cin >> a >> b;
        a--, b--;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    
    int girth = INT_MAX;
    for(int i = 0; i < n; i++){
        girth = min(bfs(i), girth);
    }

    if(girth == INT_MAX) cout << -1 << endl;
    else cout << girth << endl;
}