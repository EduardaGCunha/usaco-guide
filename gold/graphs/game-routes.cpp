#include <bits/stdc++.h>
using namespace std;

const int MAXN = 2*(1e5);
vector<int> graph[MAXN];
int visited[MAXN];
int ans = 0;
int n, m;

// void dfs(int v){
//     visited[v] = 1;
//     for(auto u : graph[v]){
//         if(!visited[u]){
//             dfs(u);
//         }
//     }
//     visited[v] = 0;
//     if(!(graph[v].size())) ans++;
// }

// int main(){
//     cin >> n >> m;
//     for(int i = 0; i < m; i++){
//         int a, b; cin >> a >> b;
//         a--, b--;
//         graph[a].push_back(b);
//     }

//     for(int i = 0; i < n; i++){
//         if(!visited[i])
//     }
// }