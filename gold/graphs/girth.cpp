#include <bits/stdc++.h>
using namespace std;

const int MAXN = 5*(1e3);
vector<int> graph[MAXN];
int n, m;
const int INF = 1e6;

int shortest_path(int x){
    vector<int> dist(n, INF);
    vector<int> visited(n, 0);

    //dist, curnode
    priority_queue<pair<int, int>> pq; 
    pq.push({0, x});

    dist[x] = 0;
    int ans = INF;
    while(!pq.empty()){
        auto [dis, v] = pq.top(); pq.pop();
       // cout << dis << " " << v << endl;
        dis = -dis;
        if(dist[v] < dis) continue;
        for(auto u : graph[v]){
            if(dist[u] == INF){
                dist[u] = dis+1;
                pq.push({-dist[u], u});
            }else if(dist[u] >= dist[v]){
                ans = min(ans, dist[u] + dist[v] + 1);
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

    int ans = INF;
    for(int i = 0; i < n; i++){
        ans = min(ans, shortest_path(i));
    }

    if(ans == INF) cout << -1 << endl;
    else cout << ans << endl;
}