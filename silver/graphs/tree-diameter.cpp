#include <bits/stdc++.h>
using namespace std;

const int MAXN = 2*(1e5)+7;
vector<int> graph[MAXN], ordemSaida;
int dis, cur;

void dfs(int v, int p, int d){
    for(auto u : graph[v]){
        if(u == p) continue;
        dfs(u, v, d+1);
    }
    if(dis < d){
        dis = d;
        cur = v;
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

    dfs(0, -1, 0);
    dfs(cur, -1, 0);
    cout << dis << endl;
}