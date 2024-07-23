#include <bits/stdc++.h>
using namespace std;

#define int long long
const int MAXN = 2*(1e5);
vector<pair<int, int>> graph[MAXN];
int parent[MAXN];
const int INF = 1e18;

int n, m; 

signed main(){
    cin >> n >> m;

    vector<int> dist(n, INF);
    for(int i = 0; i < m; i++){
        int a, b, c; cin >> a >> b >> c;
        a--, b--;
        graph[a].push_back({b, c});
    }

    using T = pair<int, int>;
    priority_queue<T, vector<T>, greater<T>> pq;
    int s = 0;
    dist[s] = 0;
    pq.push({0, s}); 

    while(!pq.empty()){
        const auto [u, v] = pq.top(); pq.pop();
        for(const auto [x, y] : graph[v]){
            if(u + y < dist[x]){
                pq.push({dist[x] = u+y, x});
                parent[x] = v;
            }
        }
    }

    vector<int> res;
    int cur = n-1;
    while(cur != 0){
        res.push_back(dist[cur]);
        cur = parent[n];
    }


    sort(res.rbegin(), res.rend());
    res[0] /=2;
    int sum = 0;
    for(auto a : res) sum += a;
    cout << sum << endl;

}