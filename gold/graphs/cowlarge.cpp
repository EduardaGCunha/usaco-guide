#include <bits/stdc++.h>
using namespace std;

#define int long long

const int MAXN = 1e5;
vector<int> graph[MAXN];
const int INF = 1e9;

signed main(){
    freopen("atlarge.in", "r", stdin);
    freopen("atlarge.out", "w", stdout);
    int n, k; cin >> n >> k;

    for(int i = 0; i < n-1; i++){
        int a, b; cin >> a >> b;
        a--, b--;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    queue<int> q;
    k--;
    q.push(k);

    vector<int> dist1(n, INF);
    dist1[k] = 0;
    while(!q.empty()){
        auto v = q.front(); q.pop();
        for(auto u : graph[v]){
            if(dist1[u] > dist1[v] + 1){
                dist1[u] = dist1[v] + 1;
                q.push(u);
            }
        }
    }

    vector<int> dist2(n, INF);
    for(int i = 0; i < n; i++){
        if(graph[i].size() == 1){
            dist2[i] = 0;
            q.push(i);
        }
    }

    while(!q.empty()){
        int v = q.front(); q.pop();
        for(auto u : graph[v]){
            if(dist2[u] > dist2[v] + 1){
                dist2[u] = dist2[v]+1;
                q.push(u);
            }
        }
    }

    q.push(k);
    int ans = 0;
    vector<int> visited(n, 0);
    while(!q.empty()){
        int c = q.front(); q.pop();
        if(dist1[c] >= dist2[c]){
            ans++;
            continue;
        }
        if(visited[c]) continue;
        visited[c] = 1;
        for(auto u : graph[c]){
            q.push(u);
        }
    }

    cout << ans << endl;
}