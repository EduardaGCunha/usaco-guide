#include <bits/stdc++.h>
using namespace std;


#define fastio ios_base::sync_with_stdio(0); cin.tie(0)
#define int long long

const int MAXN = 2*(1e5)+7;
vector<int> graph[MAXN];
int visited[MAXN], prof[MAXN], comp[MAXN], dis;

void dfs(int v, int d, int c){
    comp[v] = c;
    prof[v] = d;
    visited[v] = 1;
    for(auto u : graph[v]){
        if(!visited[u]){
            dfs(u, d+1, c);
        }
    }
    dis = max(dis, d);
}

signed main(){
    fastio;
    int n; cin >> n;
    for(int i = 0; i < n-1; i++){
        int a, b; cin >> a >> b;
        a--, b--;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

}
