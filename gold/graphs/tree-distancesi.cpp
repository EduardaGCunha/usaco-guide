#include <bits/stdc++.h>
using namespace std;

const int MAXN = 2e5+7;
vector<int> graph[MAXN];
int depth[MAXN], ans[MAXN];

void dfs(int v, int p){
    for(auto u : graph[v]){
        if(u == p) continue;
        dfs(u, v);
        depth[v] = depth[u] + 1;
    }
}

void dfs2(int v, int p, int prof){
    ans[v] = max(prof, depth[v]);

    int max1 = 0, max2 = 0;
    for(auto u : graph[v]){
        if(u == p) continue;
        if((depth[u] + 1) > max1){
            max2 = max1; 
            max1 = depth[u] + 1;
        }else if((depth[u] + 1) > max2){
            max2 = depth[u] + 1;
        }
    }

    for(auto u : graph[v]){
        if(u == p) continue;
        if(depth[u] + 1 == max1){
            dfs2(u, v, max2);
        }else dfs2(u, v, max1);
    }
}

int main(){
    int n; cin >> n;
    for(int i = 0; i < n-1; i++){
        int a, b; cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    dfs(1, 0);
    dfs2(1, 0, 0);
    for(int i = 1; i <= n; i++) cout << ans[i] << " ";
    cout << endl;
}