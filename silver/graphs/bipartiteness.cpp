#include <bits/stdc++.h>
using namespace std;

#define int long long

const int MAXN = 1e5+7;
vector<int> graph[MAXN];
int color[MAXN], cnt[MAXN], visited[MAXN];

void dfs(int v, int c){
    visited[v] = 1;
    cnt[c]++; 
    for(auto u : graph[v]){
        if(!visited[u]){
            dfs(u, !c);
        }
    }   
}

signed main(){
    int n; cin >> n;
    for(int i = 0; i < n-1; i++){
        int a, b; cin >> a >> b;
        a--, b--;
        graph[b].push_back(a);
        graph[a].push_back(b);
    }

    dfs(0, 0);

    cout << cnt[0]*cnt[1] - n+1 << endl;
}