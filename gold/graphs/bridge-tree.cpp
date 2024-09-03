#include <bits/stdc++.h>
using namespace std;

const int MAXN = 2*(1e5);
vector<int> graph[MAXN], comp_vertices[MAXN];
int pre[MAXN], visited[MAXN], low[MAXN], comp[MAXN], pilha[MAXN];
vector<pair<int,int>> res;
int t = 0, p = 0, c = 0;

void dfs(int v, int p){
    t++;
    pre[v] = t;
    low[v] = t;
    visited[v] = 1;
    p++;
    pilha[p] = v;
    for(auto u : graph[v]){
        if(!visited[u]){
            dfs(u, v);
            low[v] = min(low[v], low[u]);
        }else{
            if(u == p) continue; 

            low[v] = min(low[v], pre[u]);
        }
    }

    if(low[v] == pre[v]){
        c++;
        int vertice;
        do{
            vertice = pilha[p];
            p--;
            comp[vertice] = c;
            comp_vertices[c].push_back(vertice);
        }while(vertice != v);
    }

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
        cout << r.first+1 << " " << r.second+1 << endl;
    } 
}