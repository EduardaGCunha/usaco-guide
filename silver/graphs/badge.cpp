#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e3+7;
vector<int> graph[MAXN];
// int visited[MAXN];

// int dfs(int v){
//     if(visited[v]) return v;
//     visited[v] = 1;
//     for(auto a : graph[v]){
//         dfs(a);
//     }
// }

int main(){
    int n; cin >> n;
    for(int i = 0; i < n; i++){
        int a; cin >> a;
        a--;
        graph[i].push_back(a);
    }

    for(int i = 0; i < n; i++){
        stack<int> s;
        s.push(i);
        vector<int> visited(n, 0);
        while(!s.empty()){
            int v = s.top(); s.pop();
            for(auto u : graph[v]){
                if(!visited[u]){
                    visited[u] = 1; 
                    s.push(u);
                }else{
                    cout << u+1 << " ";
                }

            }
        }
    }
}