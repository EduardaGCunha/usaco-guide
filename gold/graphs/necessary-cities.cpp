#include <bits/stdc++.h>
using namespace std;

const int MAXN = 2*(1e5);
vector<int> graph[MAXN];
int pre[MAXN], visited[MAXN], low[MAXN];
vector<int> res;
int t = 0;

void dfs(int v, int p){
    t++;
    pre[v] = t;
    low[v] = t;
    visited[v] = 1;
    int filhos = 0;
    bool articulationpoint = false;
    for(auto u : graph[v]){
        if(!visited[u]){
            filhos++;
            dfs(u, v);
            low[v] = min(low[v], low[u]);
            if(low[u] >= pre[v]) articulationpoint = true;
        }else{
            if(u == p) continue; 
            low[v] = min(low[v], pre[u]);
        }
    }

    if(v == 0 && filhos >= 2) res.push_back(v);
    if(v != 0 && articulationpoint) res.push_back(v);
}


int main(){
    int n, m; cin >> n >> m;
    for(int i = 0; i < m; i++){
        int a, b; cin >> a >> b;
        a--, b--;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    t = 0;
    for(int i = 0; i < n; i++){
        if(!visited[i]){
            dfs(i, -1);
        }
    }

    cout << res.size() << endl;
    for(auto r : res){
        cout << r+1 << " ";
    } 
    cout << endl;
}