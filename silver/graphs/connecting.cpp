#include <bits/stdc++.h>
using namespace std;

#define int long long

const int MAXN = 5*(1e5)+7;
vector<int> graph[MAXN];
set<int> comp1[MAXN];
int visited[MAXN], comp[MAXN];

void dfs(int v, int c){
    visited[v] = 1;
    comp1[c].insert(v);
    comp[v] = c;
    for(auto u : graph[v]){
        if(!visited[u]) dfs(u, c);
    }
}

int calc(int v, int u){
    int dis = 1e18;
    int c = comp[u];
    auto a = comp1[c].lower_bound(v);

    if(a != comp1[c].end()){
        int val = *a;
        dis = min(dis, (val-v)*(val-v));
    }
    if(a != comp1[c].begin()){
        --a;
        int val = *a;
        dis = min(dis, (val-v)*(val-v));
    }
    return dis;
}

signed main(){
    int t; cin >> t;
    while(t--){
        int n, m; cin >> n>> m;
        for(int i = 0; i < n; i++){
            graph[i].clear();
            visited[i] = 0;
            comp1[i].clear();
            comp[i] = 0;
        }
        for(int i = 0; i < m; i++){
            int a, b; cin >> a >> b;
            a--, b--;
            graph[a].push_back(b);
            graph[b].push_back(a);
        }

        int c = 0;
        for(int i = 0; i < n; i++){
            if(!visited[i]){
                c++;
                dfs(i, c);
            }
        }

        if(comp[0] == comp[n-1])cout << "0" << endl;
        else{
            int rs = 1e18;
            for(int i = 0; i < c; i++){
                int aresta1 = 1e18, aresta2 = 1e18;
                for(auto v : comp1[i]){
                    aresta1 = min(aresta1, calc(v, 0));
                    aresta2 = min(aresta2, calc(v, n-1));
                    rs = min(rs, aresta1+aresta2);
                }
            }

            cout << rs << endl;
        }
    }
}