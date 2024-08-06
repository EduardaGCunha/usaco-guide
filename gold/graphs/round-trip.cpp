#include <bits/stdc++.h>
using namespace std;
 
const int MAXN = 2*(1e5)+7;
vector<int> graph[MAXN];
int visited[MAXN], parent[MAXN];
int head = -1;
vector<int> path;
bool push = true;
 
 
bool dfs(int v, int p){
    //cout << v << " " << p << endl;
    if(visited[v]){
        //cout << v << " " << p << endl;
        path.push_back(v);
        return true; 
    }
    
    
    visited[v] = 1;
    for(auto u : graph[v]){
        //cout << u << " " << v << endl;
        if(u != p){
            //cout << u << " " << v << endl;
            if(dfs(u, v)){
                if(push) path.push_back(v);
                if(path.front() == path.back()){
                    push = false;
                }
                return true;
            }
        }
    }
    return false;
}
 
int main(){
    int n, m; cin >> n >> m;
    for(int i = 0; i < m; i++){
        int a, b; cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
 
    //push = true;
    bool ans = false;
    for(int i = 1; i <= n; i++){
        if(!visited[i]){
            if(dfs(i, -1)){
                ans = true;
                break;
            }
        }
    }
    if(!ans || path.back() != path.front()){
        cout << "IMPOSSIBLE" << endl;
        return 0;
    }
    cout << path.size() << endl;
    for(auto a : path){
        cout << a << " ";
    }
    cout << endl;
}