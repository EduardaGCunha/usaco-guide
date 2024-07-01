#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(0); cin.tie(0)
#define int long long


const int MAXN = 2*(1e5)+7;
vector<int> graph[MAXN];
int color[MAXN];

bool dfs(int v){
    int c = color[v] == 1 ? 2 : 1;
    for(auto u : graph[v]){
        if(!color[u]){
            color[u] = c;
            if(!dfs(u)) return false;
        }else if(color[u] == color[v]) return false;
    }
    return true;
}

signed main(){
    fastio;
    int n, m; cin >> n >> m;
    for(int i = 0; i < m; i++){
        int a, b; cin >> a >> b;
        a--, b--;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    for(int i = 0; i < n; i++){
        if(!color[i]){
            color[i] = 1;
            if(!dfs(i)){
                cout << "IMPOSSIBLE" << endl;
                return 0;
            }
        }
    }

    for(int i = 0; i < n; i++){
        cout << color[i] << " ";
    }
    cout << endl;
}