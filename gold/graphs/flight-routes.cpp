#include <bits/stdc++.h>
using namespace std;

#define int long long

const int INF = 1e18;
const int MAXN = 2*(1e5)+7;
vector<pair<int, int>> graph[MAXN];
vector<vector<int>> dist;


signed main(){
    int n, m, k; cin >> n >> m >> k;

    for(int i = 0; i < m; i++){
        int a, b, c; cin >> a >> b >> c;
        a--, b--;
        graph[a].push_back({b, c});
    }

    dist.resize(n, vector<int>(k, INF));

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    dist[0][0] = 0;
    pq.push({0, 0});
    while(!pq.empty()){
        auto [d, v] = pq.top(); pq.pop();

        if(dist[v][k-1] < d) continue;

        for(auto [u, dis]: graph[v]){
            if(dist[u][k-1] > dis+d){
                dist[u][k-1] = dis+d;
                pq.push({dis+d, u});
                sort(dist[u].begin(), dist[u].end());
            } 
        }
    }

    for(int i = 0; i < k; i++){
        cout << dist[n-1][i] << " ";
    }
    cout << endl;
    
}