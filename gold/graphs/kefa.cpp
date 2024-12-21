#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e5+7;
vector<int> graph[MAXN];
int cats[MAXN];
int n, m, res = 0;

void dfs(int v, int p, int cnt){
    if(cats[v]) cnt++;
    else cnt = 0;
    if(cnt > m) return;
    if(graph[v].size() == 1 && p != 0) res++;
    for(auto u : graph[v]){
        if(u == p) continue;
        dfs(u, v, cnt);
    }
}


int main(){
    cin >> n >> m;
    for(int i = 1; i <= n; i++) cin >> cats[i];
    for(int i = 0; i < n-1; i++){
        int a, b; cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    dfs(1, 0, 0);
    cout << res << endl;
} 