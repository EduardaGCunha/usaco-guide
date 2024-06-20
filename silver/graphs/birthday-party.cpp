#include <bits/stdc++.h>
using namespace std;

const int MAXN = (1e5)+7;
vector<int> graph[MAXN];
int pre[MAXN], visited[MAXN], vis[MAXN], low[MAXN];
int t, cnt = 0;

void dfs(int v, int pai){
    t++;
    pre[v] = t;
    low[v] = t;
    visited[v] = 1;
    for(auto u : graph[v]){
        if(!visited[u]){
            dfs(u, v);
            low[v] = min(low[v], low[u]);
        }else{
            if(u == pai) continue;
            low[v] = min(low[v], pre[u]);
        }
    }

    if(v != 0 && low[v] == pre[v]){
        cnt++;
    }
}

void dfs2(int v){
    vis[v] = 1;
    for(auto a : graph[v]){
        if(!vis[a]){
            dfs2(a);
        }
    }
}


int main(){ 
    int n, m; 
    while(cin >> n >> m){
        if(n == 0 && m == 0) break;
        for(int i = 0; i < m; i++){
            int a, b; cin >> a >> b;
            graph[a].push_back(b);
            graph[b].push_back(a);
        }
        int c = 0;
        for(int i = 0; i < n; i++){
            if(!vis[i]){
                dfs2(i);
                c++;
            }
        }
        if(m == 0){
            cout << "No" << endl;
            t = 0, cnt = 0;
            for(int i = 0; i < n; i++){
                visited[i] = 0;
                pre[i] = 0;
                low[i] = 0;
                graph[i].clear();
                vis[i] = 0;
            }
        }
        if(c > 1){
            //cout << c << endl;
            cout << "Yes" << endl;
            t = 0, cnt = 0;
            for(int i = 0; i < n; i++){
                visited[i] = 0;
                pre[i] = 0;
                low[i] = 0;
                graph[i].clear();
                vis[i] = 0;
            }
            continue;
        }
        dfs(0, 0);
        if(cnt > 0) cout << "Yes" << endl;
        else cout << "No" << endl;
        t = 0, cnt = 0;
        for(int i = 0; i < n; i++){
            visited[i] = 0;
            pre[i] = 0;
            low[i] = 0;
            graph[i].clear();
            vis[i] = 0;
        }
    }
}