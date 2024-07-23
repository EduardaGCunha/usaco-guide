#include <bits/stdc++.h>
using namespace std;

#define int long long 

const int MAXN = 2*(1e5)+7;
vector<int> graph[MAXN];
int maxdist[MAXN], ans[MAXN], n;

void dfs(int v, int p){
    for(auto u : graph[v]){
        if(u == p) continue;
        dfs(u, v);
        maxdist[v] = max(maxdist[v], maxdist[u]+1);
    }
}

void dfs2(int v, int p, int dist){
    ans[v] = max(maxdist[v], dist);

    int max1 = 0, max2 = 0;
    for(auto u : graph[v]){
        if(u == p) continue;
        if(maxdist[u] + 1 > max1){
            max2 = max1;
            max1 = maxdist[u]+1;
        }else if((maxdist[u]+1) > max2){
            max2 = maxdist[u]+1;
        }
    }

    for(auto u : graph[v]){
        if(u == p) continue;
        if(maxdist[u]+1 == max1){
            dfs2(u, v, max(dist, max2)+1);
        }else dfs2(u, v, max(max1, dist)+1);
    }
}

signed main(){
    cin >> n;
    for(int i = 0; i < n-1; i++){
        int a, b; cin >> a >> b;
        a--, b--;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    dfs(0, -1);
    dfs2(0, -1, 0);
    for(int i = 0; i < n; i++){
        cout << ans[i] << " ";
    }
    cout << endl;
}