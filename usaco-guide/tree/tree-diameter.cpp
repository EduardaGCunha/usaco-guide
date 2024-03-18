#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(0); cin.tie(0)
#define int long long

const int MAXN = 200006;
int dis, m;
vector<int> graph[MAXN];
int dist[MAXN], visited[MAXN];

void dfs(int v, int p, int d){
    for(auto a : graph[v]){
        if(a == p) continue;
        dfs(a, v, d + 1);
    }
    if(d > dis){
        dis = d;
        m = v;
    }
}

signed main(){
    fastio;
    int n; cin >> n;
    for(int i = 0; i < n - 1; i++){
        int a, b; cin >> a >> b;
        a--, b--;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    dfs(0, -1, 0);
    dfs(m, -1, 0);
    cout << dis << endl;

}