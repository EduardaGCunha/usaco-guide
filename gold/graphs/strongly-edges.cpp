#include <bits/stdc++.h>
using namespace std;

const int MAXN = 2*1e5;
vector<pair<int, int>> res;
vector<int> graph[MAXN];
int visited[MAXN], low[MAXN], comp[MAXN], pre[MAXN];
int t;
bool ans = true;

void check(int v, int c){
    comp[v] = c;
    for(auto u : graph[v]){
        if(!comp[u]) check(u, c);
    }
}

void dfs(int v, int p){
    t++;
    low[v] = t;
    pre[v] = t;
    visited[v] = 1;
    for(auto u : graph[v]){
        if(!visited[u]){
            dfs(u, v);
            low[v] = min(low[v], low[u]);
        }else{
            if(u == p) continue;
            low[v] = min(low[v], pre[u]);
            if(pre[u] < pre[v]){
                res.push_back({v, u});
            }
        }
    }

    if(v != 0 && low[v] == pre[v]) ans = false;
    else if(v != 0) res.push_back({p, v});
}



int main(){
    int n, m; cin >> n >> m;
    t = 0;

    for(int i = 0; i < m; i++){
        int a, b; cin >> a >> b;
        a--, b--;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    dfs(0, -1);

    int c = 0;
    for(int i = 0; i < n; i++){
        if(!comp[i]){
            c++;
            check(i, c);
        }
    }

    if(!ans || c > 1){
        cout << "IMPOSSIBLE" << endl;
        return 0;
    }
    for(auto r : res){
        cout << r.first+1 << " " << r.second+ 1 << endl;
    }
}