#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(0); cin.tie(0)
#define int long long

const int MAXN = 150000;
int color[MAXN], dist[MAXN];
vector<int> graph[MAXN];

bool dfs(int v){
    int cur = color[v];
    int c = cur == 1 ? 2 : 1;
    for(auto a : graph[v]){
        if(color[a] != 0){
            if(color[a] != c) return false;
        }else{
            color[a] = c;
            if(!dfs(a)){
                return false;
            }
        }
    }
    return true;
}

signed main(){
    fastio;
    int n, m; cin >> n >> m;
    for(int i =0; i < m; i++){
        int a, b; cin >> a >> b;
        a--, b--;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    bool valid = true;

    for(int i = 0; i < n; i ++){
        if(color[i] == 0){
            color[i] = 1;
            if(!dfs(i)){
                valid = false;
            }
        }
    }

    if(valid){
        for(int i = 0; i < n; i++){
            cout << color[i] << " ";
        }
        cout << "\n";
        return 0;
    }
    cout << "IMPOSSIBLE\n";
    
}