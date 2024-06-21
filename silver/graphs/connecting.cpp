#include <bits/stdc++.h>
using namespace std;

#define int long long

const int MAXN = 1e5;
vector<int> graph[MAXN]; 
set<int> comp1[MAXN];
int visited[MAXN], comp[MAXN];

int calc(int v, int u){
    int dist = 1e18;
    int c = comp[v];
    auto a = comp1[c].lower_bound(v); 

    if(a != comp1[c].end()){
        int val = *a;
        dist = min(dist, (val-v)*(val-v));
    }
    if(a != comp1[c].begin()){
        auto b = --a;
        int val = *b;
        dist = min(dist, (val-v)*(val-v));
    }
    return dist;
}

void dfs(int v, int c){
    comp1[c].insert(v);
    comp[v] = c;
    visited[v] = 1;
    for(auto a : graph[v]){
        if(!visited[a]) dfs(a, c);
    }
}

signed main(){
    int t; cin >> t;
    while(t--){
        int n, m; cin >> n >> m;
        for(int i = 0; i < n; i++){
            graph[i].clear();
            comp[i] = 0;
            visited[i] = 0;
            comp1[i].clear();
        }
        for(int i = 0; i < m; i++){
            int a, b; cin >> a >> b;
            a--; b--;
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

        if(comp[0] == comp[n-1]){
            cout << "0" << endl;
            continue;
        }

        int res = 1e11;
        for(int i = 0; i < c; i++){
            int a = 1e11, b = 1e11;
            for(auto v : comp1[c]){
                int a = min(a, calc(v, 1));
                int b = min(b, calc(b, 1));
                res = min(res, a+b);

            }
        }

        cout << res << endl;
    }
}