#include <bits/stdc++.h>
using namespace std;

const int MAXN = 2*(1e5);
vector<int> graph[MAXN];
int visited[MAXN], comp[MAXN];

void dfs(int v, int c){
    visited[v] = 1;
    comp[v] = c; 
    for(auto u : graph[v]){
        if(!visited[u]) dfs(u, c);
    }
}

int main(){
    int n, m; cin >> n >> m;
    for(int i = 0; i < m; i++){
        int a, b; cin >> a >> b;
        a--, b--;
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

    cout << c - 1 << endl;
    set<int> s;
    vector<int> ans;
    for(int i = 0; i < n; i++){
        if(s.count(comp[i]) == 0) ans.push_back(i);
        s.insert(comp[i]);
    }

    for(int i = 0; i < c-1; i++){
        //if(ans[i] == 0 || ans[i+1] == 0) break;
        cout << ans[i]+1 << " " << ans[i+1]+1 << endl;
    }

}