#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(0); cin.tie(0)
#define int long long
#define endl '\n'


const int MAXN = 2e3+7;
int grid[MAXN][MAXN];
vector<pair<int, int>> graph[MAXN];
const int INF = 1e18;
struct DSU{
    int n;
    vector<int> p; 
    vector<int> r;
    DSU(int _n){
        n = _n; 
        p.resize(n);
        r.resize(n);
        for(int i = 0; i < n; i++){
            p[i] = i;
            r[i] = 0;
        }
    }

    int find(int x){
        return (p[x] == x? x : p[x] = find(p[x]));
    }

    bool unite(int a, int b){
        a = find(a), b = find(b);
        if(a == b) return false;
        if(r[a] == r[b]) r[a]++;
        if(r[a] > r[b]){
            r[a] += r[b];
            p[b] = a;
        }else{
            r[b] += r[a];
            p[a] = b;
        }
        return true;
    }
    
};

signed main(){
    fastio;
    int n; cin >> n;
    int pos = 1, pos2 = 1;
    vector<tuple<int, int, int>> edges;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> grid[i][j];
            if(grid[i][j]) pos2 = 0;
            if(i == j){
                if(grid[i][j]) pos = 0;
                continue;
            }
            edges.push_back({grid[i][j], i, j});
        }
    }
    sort(edges.begin(), edges.end());
    DSU dsu(n);
    for(auto [w, a, b] : edges){
        if(dsu.unite(a, b)){
            graph[a].push_back({b, w});
            graph[b].push_back({a, w});
        }
    }
    for(int i = 0; i < n; i++){
        vector<int> dist(n, INF);
        queue<pair<int, int>> q;
        q.push({0, i});
        dist[i] = 0;
        while(!q.empty()){
            auto [d, v] = q.front(); q.pop();
            for(auto [u, w]: graph[v]){
                if(dist[u] > dist[v] + w){
                    dist[u] = dist[v] + w;
                    q.push({dist[u], u});
                }
            }
        }
        for(int j = 0; j < n; j++){ 
            if(grid[i][j] != dist[j]){
                pos = 0;
                break;
            }
        }
    }
    if(pos && !pos2) cout << "YES" << endl;
    else cout << "NO" << endl;
}