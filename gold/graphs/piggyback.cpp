#include <bits/stdc++.h>
using namespace std;

const int MAXN = 4*(1e4);
vector<int> graph[MAXN];
int dist[3][MAXN];
const int INF = 1e9;

int b, e, p, n, m;

void bfs(int a, int x, int pos){
    for(int i = 0; i < n; i++) dist[pos][i] = INF;
    queue<int> q;
    q.push(a);
    dist[pos][a] = 0;

    while(!q.empty()){
        int v = q.front(); q.pop();
        for(auto u : graph[v]){
            if(dist[pos][u] == INF){
                dist[pos][u] = dist[pos][v]+x;
                q.push(u);
            }
        } 
    }
}

int main(){
    freopen("piggyback.in", "r", stdin);
    freopen("piggyback.out", "w", stdout);
    cin >> b >> e >> p >> n >> m;

    for(int i = 0; i < m; i++){
        int a, b; cin >> a >> b;
        a--, b--;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    bfs(0, b, 0);
    bfs(1, e, 1);
    bfs(n-1, p, 2);
    int ans = INF;
    for(int i = 0; i < n; i++){
        cout << dist[0][i]+dist[1][i] + dist[2][i] << endl;
        ans = min(ans, dist[0][i]+dist[1][i]+dist[2][i]);
    }

    cout << ans << endl;
}