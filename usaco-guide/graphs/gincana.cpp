#include <bits/stdc++.h>
using namespace std;

const int MAXN = 5007;
vector<int> graph[MAXN];
int visited[MAXN];

void dfs(int v){
    visited[v] = 1;
    for(auto a : graph[v]){
        if(!visited[a]) dfs(a);
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

    int t = 0;
    for(int i = 0; i < n; i++){
        if(!visited[i]){
            t++;
            dfs(i);
        }
    }

    cout << t << endl;
}