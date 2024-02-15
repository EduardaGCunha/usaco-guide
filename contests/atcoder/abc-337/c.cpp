#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(0); cin.tie(0)
#define int long long

const int MAXN = 350000;
vector<int> graph[MAXN]; 
int visited[MAXN];

void dfs(int v){
    visited[v] = 1;
    for(int i = 0; i < graph[v].size(); i++){
        int viz = graph[v][i];
        if(visited[viz] == 0){
            dfs(viz);
        }
    }
}


signed main(){
    fastio;
    int n; cin >> n;
    int first = -1;
    for(int i = 1; i <= n; i++){
        int a; cin >> a;
        if(a == -1){
            first = i;
            continue;
        }
        graph[a].push_back(i);
    }
    dfs(first);
    cout << endl;
}