#include <bits/stdc++.h>
using namespace std;

#define ll long long 
const ll INF = 1e18;
const ll MOD = (1e9+7);
const int MAXN = 2*(1e5);
vector<pair<int, ll>> graph[MAXN];
ll dist[MAXN]; 
int cnt[MAXN], minflights[MAXN], maxflights[MAXN];

int main(){
    //freopen("input.txt", "r", stdin);
    int n, m; cin >> n >> m;

    for(int i = 0; i < m; i++){
        int a, b; ll c;
        cin >> a >> b >> c;
        a--, b--;
        graph[a].push_back({b, c});
    }

    for(int i = 0; i < n; i++) dist[i] = INF;
    priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> pq;
    dist[0] = 0;
    pq.push({0, 0}); //node, dis;
    minflights[0] = 0;
    maxflights[0] = 0; 
    cnt[0] = 1;
    while(!pq.empty()){
        auto [dis, v] = pq.top(); pq.pop();
        for(auto u : graph[v]){
            ll new_cost = u.second + dis;
            if(dist[u.first] > new_cost){
                dist[u.first] = new_cost;
                pq.push({new_cost, u.first});
                minflights[u.first] = minflights[v]+1;
                maxflights[u.first] = maxflights[v]+1;
                cnt[u.first] = (cnt[v]);
            }
            else if(dist[u.first] == new_cost){
                cnt[u.first] = (cnt[u.first] + cnt[v])%MOD;
                minflights[u.first] = min(minflights[u.first], minflights[v]+1);
                maxflights[u.first] = max(maxflights[u.first], maxflights[v]+1);
            }
        }
    }

    cout << dist[n-1] << " " << cnt[n-1] << " " << minflights[n-1] << " " << maxflights[n-1] << endl;



}