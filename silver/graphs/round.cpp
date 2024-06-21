#include <bits/stdc++.h>
using namespace std;

const int MAXN = 2*(1e5);
set<int> graph[MAXN];
int visited[MAXN], comp[MAXN];

void dfs(int v, int c){
    comp[v] = c;
    visited[v] = 1;
    for(auto a : graph[v]){
        if(!visited[a]) dfs(a, c);
    }
}

int main(){
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        for(int i = 0; i < n; i++){
            graph[i].clear();
            visited[i] = 0;
            comp[i] = 0;
        }
        for(int i = 0; i < n; i++){
            int a; cin >> a;
            a--;
            graph[i].insert(a);
            graph[a].insert(i);
        }

        int c = 0;
        for(int i = 0; i < n; i++){
            if(!visited[i]){
                c++;
                dfs(i, c);
            }
        }   
        
        vector<int> vis(c, 0);
        int cnt = 0;
        for(int i = 0; i < n; i++){
            if(graph[i].size() <= 1 && !vis[comp[i]]){
                vis[comp[i]] = 1;
                cnt++;
                //cout << "chegou aqui" << endl;
            }
        }
        if(cnt%2 == 1) cnt--;
        cout << c - cnt << " " << c << endl;
    }
}