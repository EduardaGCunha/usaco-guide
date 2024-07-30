#include <bits/stdc++.h>
using namespace std;

#define ll long long
int n, m; 

const ll INF = 1e18;
const int MAXN = 2*(1e5)+7;
vector<pair<int, ll>> graph[MAXN];
ll dist[MAXN][2];

int main(){
    cin >> n >> m;
    for(int i = 0; i < m; i++){
        int a, b; ll c; 
        cin >> a >> b >> c;
        a--, b--;
        graph[a].push_back({b, c});
    }

    for(int i = 0; i < n; i++){
        dist[i][0] = INF;
        dist[i][1] = INF;
    }

    priority_queue<tuple<ll, int, bool>, vector<tuple<ll, int, bool>>, greater<tuple<ll, int, bool>>> pq;
    dist[0][0] = 0;
    pq.push({0, 0, false});
    
    while(!pq.empty()){
        auto [dis, node, coupon] = pq.top();
        pq.pop();

        if(dis > dist[node][coupon]) continue;

        for(auto u : graph[node]){
            ll new_cost = dis + u.second;
            if(dist[u.first][coupon] > new_cost){
                dist[u.first][coupon] = new_cost;
                pq.push({new_cost, u.first, coupon});
            }

            new_cost = dis + (u.second/2);
            if(!coupon && dist[u.first][1] > new_cost){
                dist[u.first][1] = new_cost;
                pq.push({new_cost, u.first, true});

            }
        }
    }

    cout << min(dist[n-1][0], dist[n-1][1]) << endl;


}