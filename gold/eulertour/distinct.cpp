#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(0); cin.tie(0)
#define int long long
#define endl "\n"

const int MAXN = 2*1e5+7;
set<int> distinct[MAXN];
vector<int> graph[MAXN];
int ans[MAXN];

void dfs(int v, int p){ 
    for(auto u : graph[v]){
        if(u == p) continue;
        dfs(u, v);
        if(distinct[u].size() > distinct[v].size()) swap(distinct[u], distinct[v]);
        //set<int> temp = distinct[v];
        for(auto x : distinct[u]) distinct[v].insert(x);
        //distinct[u] = temp;
    }
    ans[v] = distinct[v].size();
}

signed main(){
    fastio;
    int n; cin >> n;
    for(int i = 0; i < n; i++){
        int x; cin >> x;
        distinct[i].insert(x);
    }

    for(int i = 0; i < n-1; i++){
        int a, b; cin >> a >> b;
        a--, b--;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    dfs(0, 0);

    for(int i = 0; i < n; i++){
        cout << ans[i] << " ";
    }
    cout << endl;
}