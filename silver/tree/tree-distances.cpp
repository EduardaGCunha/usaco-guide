#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(0); cin.tie(0)
#define int long long

const int MAXN = 200007;
vector<int> graph[MAXN];
int dis, m;

void dfs(int v, int p, int d){
    for(auto a : graph[v]){
        if(a == p) continue;
        dfs(a, v, d+1);
    }
    if(d > dis){
        dis = d;
        m = v;
    }
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
    
    for(int i = 0; i < n; i++){
        dis = 0;
        dfs(i, -1, 0);
        cout << dis << " ";
    }
    cout << endl;
}