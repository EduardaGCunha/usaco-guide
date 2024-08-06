#include <bits/stdc++.h>
using namespace std;

#define int long long

const int MAXN = 1e4;
const int INF = 1e18;
vector<pair<int, int>> graph[MAXN];
int visited[MAXN], haybale[MAXN], ans[MAXN], dist[MAXN];

signed main(){
    int n, m, k; cin >> n >> m >> k;
    for(int i = 0; i < m; i++){
        int a, b, c; cin >> a >> b >> c;
        a--, b--;
        graph[a].push_back({b, c});
        graph[b].push_back({a, c});
    }

    for(int i = 0; i < k; i++){
        int a, c; cin >> a >> c;
        haybale[a] = c;
    }

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    
    //for each index of this cow
    for(int i = 0; i < n-1; i++){
        memset(dist, INF, n);
        dist[i] = 0;
        pq.push({i, 0});
        while(!pq.empty()){
            auto [v, dis] = pq.top(); pq.pop();
            
            for(auto [u, d] : graph[v]){
                if(haybale[u] && (dist[v] + d < haybale[u])){
                    ans[i] = 1;
                }if(dist[u] > dist[v] + d){
                    dist[u] = dist[v] + d;
                    pq.push({u, dist[u]});
                }
            }
        }
        cout << ans[i] << endl;
    }
}