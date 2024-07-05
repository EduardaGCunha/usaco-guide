#include <bits/stdc++.h>
using namespace std;

const int MAXN = 2*(1e5)+7;
vector<int> graph[MAXN], ordemSaida;
int dis[MAXN], c = 0;

void dfs(int v, int p){
    for(auto a : graph[v]){
        if(a != p){
            dfs(a, v);
        }
    }
    ordemSaida.push_back(v);
}

void dfs2(int v, int p){
    for(auto a : graph[v]){
        if(a != p){
            dfs(a, v);
            c++;
        }
    }
}

int main(){
    int n; cin >> n;
    for(int i = 0; i < n-1; i++){
        int a, b; cin >> a >> b;
        a--, b--;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    dfs(0, -1);
    dfs2(ordemSaida[n-2], -1);
    cout << c << endl;
}