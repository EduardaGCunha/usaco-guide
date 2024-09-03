#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e4;
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

int main(){
    int t; cin >> t;
    while(t--){
        int n; cin >> n;

        ordemSaida.clear();
        for(int i = 0; i < n; i++){
            graph[i].clear();
            reverso[i].clear();
            visited[i] = 0;
        }

        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                char c; cin >> c;
                if(c == 'Y'){
                    graph[i].push_back(j);
                    reverso[j].push_back(i);
                }
            }
        }

        for(int i = 0; i < n; i++){
            if(!visited[i]) dfs(i);
        }

        int c = 0;
        reverse(ordemSaida.begin(), ordemSaida.end());
        for(auto u : ordemSaida){
            if(visited[u] == 1){
                c++;
                dfs2(u, c);
            }
        }

        cout << c << endl;
    }
}