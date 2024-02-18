#include <bits/stdc++.h>
using namespace std;
 
const int MAXN = 200007;
vector<int> graph[MAXN], reverso[MAXN], ordem;
int visited[MAXN];
 
void dfs(int v){
    visited[v] = 1;
    for(auto a : graph[v]){
        if(!visited[a]) dfs(a);
    }
}
 
void dfs2(int v){
    visited[v] = 2;
    for(auto a : reverso[v]){
        if(visited[a] == 1) dfs2(a);
    }
}
 
int main(){
    int n, m; cin >> n >> m;
    for(int i = 1; i <= m; i++){
        int a, b; cin >> a >> b;
        graph[a].push_back(b);
        reverso[b].push_back(a);
    }
 
    dfs(1), dfs2(1);
    for(int i = 1; i<= n; i++){
        if(visited[i] == 0){
            cout << "NO" << endl;
            cout << 1 << " " << i << endl;
            return 0;
        }
        if(visited[i] == 1){
            cout << "NO" << endl;
            cout << i << " " << 1 << endl;
            return 0;
        }
    }
    cout << "YES" << endl;
}