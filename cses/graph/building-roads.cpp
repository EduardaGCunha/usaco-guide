#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(0); cin.tie(0)
#define int long long

const int MAXN = 150000;
vector<int> graph[MAXN]; 
int visited[MAXN], connections[MAXN];

void dfs(int v, int c){
    visited[v] = 1;
    connections[v] = c;
    for(auto a : graph[v]){
        if(visited[a] == 0) dfs(a, c);
    }
}

signed main(){
    fastio;
    int n, m; cin >> n >> m;
    for(int i = 1; i <= m; i++){
        int a, b; cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    int c = 0;
    for(int i = 1; i <= n; i++){
        if(visited[i] == 0){
            c++;
            dfs(i, c);
        }
    }

    set<int> s;
    vector<int> ans;
    for(int i = 1; i <= n; i++){
        if(s.count(connections[i]) == 0){
            ans.push_back(i);
        }
        s.insert(connections[i]);
    }
    
    cout << c-1 << endl;
    for(int i = 0; i <= c; i++){
        if(ans[i] == 0 || ans[i+1] == 0) break;
        cout << ans[i] << " " << ans[i+1] << endl;
    }

}