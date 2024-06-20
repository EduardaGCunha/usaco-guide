#include <bits/stdc++.h>
using namespace std;

#define int long long

const int MAXN = 2*(1e5)+7;
vector<int> graph[MAXN], reverso[MAXN], ordemSaida;
int visited[MAXN], comp[MAXN];

void dfs(int v){
    visited[v] = 1;
    for(auto u : graph[v]){
        if(!visited[u]) dfs(u);
    }
    ordemSaida.push_back(v);
}

void dfs2(int v, int c){
    visited[v] = 2;
    comp[v] = c;
    for(auto u : reverso[v]){
        if(visited[u] == 1) dfs2(u, c);
    }
}

signed main(){
    int n, m; cin >> n >> m;
    for(int i = 0; i < m; i++){
        int a, b; cin >> a >> b;
        a--, b--;
        graph[a].push_back(b);
        reverso[b].push_back(a);
    }

    for(int i = 0; i < n; i++){
        if(!visited[i]) dfs(i);
    }

    int c = 0;
    vector<int> nodes;
    for(int i = ordemSaida.size()-1; i >= 0; i--){
        if(visited[ordemSaida[i]] == 1){
            c++;
            nodes.push_back(ordemSaida[i]);
            dfs2(ordemSaida[i], c);
        }
    }

    if(c>1){
        cout << "NO" << endl;
        cout << nodes.back()+1 << " " << nodes[0]+1 << endl;
    }else cout << "YES" << endl;
}