#include <bits/stdc++.h>
using namespace std;

#define int long long
const int MAXN = 2*(1e5);
vector<int> graph[MAXN];
int visited[MAXN], dist[MAXN], head[MAXN];
 

signed main(){
    int n, m; cin >> n >> m;
    for(int i = 0; i < m; i++){
        int a, b; cin >> a >> b;
        a--, b--;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    queue<int> q;
    q.push(0);
    for(int i = 0; i < n; i++) dist[i] = 1e12;
    dist[0] = 1;
    while(!q.empty()){
        int v = q.front(); q.pop();
        for(auto u : graph[v]){
            if(dist[u] == 1e12){
                head[u] = v;
                dist[u] = dist[v]+1;
                q.push(u);
            }
        }
    }

    if(dist[n-1] == 1e12) cout << "IMPOSSIBLE" << endl;
    else{
        cout << dist[n-1] << endl;
        vector<int> res;
        int cur = n-1;
        while(cur != 0){
            res.push_back(cur);
            cur = head[cur];
        }

        res.push_back(0);
        for(int i = res.size()-1; i >= 0; i--){
            cout << res[i]+1 << " ";
        }
        cout << endl;
    }
}