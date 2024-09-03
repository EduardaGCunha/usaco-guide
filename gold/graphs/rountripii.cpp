#include <bits/stdc++.h>
using namespace std;

const int MAXN = 2*(1e5);
vector<int> graph[MAXN], ordemSaida;
int visited[MAXN];
bool ans = false;

void dfs(int v){
    visited[v] = 1;
    for(auto u : graph[v]){
        if(!visited[u]){
            dfs(u);
        }else if(visited[u] == 1){
            ans = true;
            ordemSaida.push_back(v);
        }
    }
    visited[v] = 2;
}

int main(){
    int n, m; cin >> n >> m;
    for(int i = 0; i < m; i++){
        int a, b; cin >> a >> b;
        a--, b--;
        graph[a].push_back(b);
    }

    for(int i = 0; i < n; i++){
        if(!visited[i]){
            dfs(i);
        }
    }

    if(!ans){
        cout << "IMPOSSIBLE" << endl;
        return 0;
    }

    for(auto u : ordemSaida) cout << u << " ";
    cout << endl;
}