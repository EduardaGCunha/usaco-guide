#include <bits/stdc++.h>
using namespace std;
 
vector<int>graph[200005];
int visited[200005];
int dis[200005];

 
void dfs(int v, int d){
    visited[v] = 1;
    dis[v] = d;
    for(auto n : graph[v]){
        if(visited[n] == 0){
            dfs(n, d+1);
        }
    }
}
 
int main(){
    int n;
    cin >> n;
    memset(visited, 0, sizeof(visited));
    memset(dis, 0, sizeof(dis));
    vector<vector<int>> graph(n);
    for(int i = 0; i < n-1; i++){
        int a, b;
        cin >> a >> b;
        a--; b--;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
 
    cout<<visited[0] << endl;
    dfs(0, 0);
 
    int m = 0;
    int pos = -1;
    for(int i = 0; i < n; i++){
        if(dis[i] > m){
            pos = i;
            m = dis[i];
        }
    }
 
    memset(visited, 0, sizeof(visited));
    memset(dis, 0, sizeof(dis));
 
    dfs(pos, 0);
 
    m = 0;
    for(int i = 0; i < n; i++){
        m = max(m, dis[i]);
    }
 
    cout << m;
 
}