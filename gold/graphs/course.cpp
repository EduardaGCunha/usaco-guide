#include <bits/stdc++.h>
using namespace std;

const int MAXN = 2*(1e5);
vector<int> graph[MAXN], ordemSaida;
int visited[MAXN], indeg[MAXN], stack[MAXN];
bool ans = true;

void dfs(int v){
    visited[v] = 1;
    for(auto u : graph[v]){
        if(!visited[u]){
            dfs(u);
        //backedge found
        }else if(visited[u] == 1) ans = false;
    }
    visited[v] = 2;
    ordemSaida.push_back(v);
}


int main(){
    int n, m; cin >> n >> m;

    for(int i = 0; i < m; i++){
        int a, b; cin >> a >> b;
        a--, b--;
        graph[a].push_back(b);
    }


    int cnt = 0;
    for(int i = 0; i < n; i++){
        if(!visited[i]){
            dfs(i);
        }
    }

    if(!ans){
        cout << "IMPOSSIBLE" << endl;
        return 0;
    }
 
    reverse(ordemSaida.begin(), ordemSaida.end());
    for(auto v : ordemSaida) cout << v+1 << " ";
    cout << endl;
    
}