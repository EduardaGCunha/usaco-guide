#include <bits/stdc++.h>
using namespace std;

#define int long long

const int MAXN = 1e4+7;
vector<array<int, 3>> graph[MAXN];
const int INF = 1e16;


signed main(){
    freopen("pump.in", "r", stdin);
    freopen("pump.out", "w", stdout);
    int n, m; cin >> n >> m;
    for(int i = 0; i < m; i++){
        int a, b, c, d; cin >> a >> b >> c >> d;
        a--, b--;
        graph[a].push_back({b, c, d});
        graph[b].push_back({a, c, d});
    }

    //dist, curmin, node
    priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<tuple<int, int, int>>> pq;
    //dist, curmin
    vector<int> dist(n, 0);
    pq.push({0, INF, 0});
    dist[0] = 0;

    while(!pq.empty()){
        auto [dis, curmin, v] = pq.top(); pq.pop();
        for(auto u : graph[v]){
            int temp = min(u[2], curmin);
            int val = temp*1e6/(dis + u[1]);
            if(dist[u[0]] < val){
                dist[u[0]] = val;
                pq.push({(dis + u[1]), temp, u[0]});
            }
        }
    }

    cout << dist[n-1] << endl;

}