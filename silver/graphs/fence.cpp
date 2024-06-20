#include <bits/stdc++.h>
using namespace std;

#define int long long

const int MAXN = (1e5)+7;
vector<int> graph[MAXN], comp[MAXN];
pair<int,int> coord[MAXN];
int visited[MAXN];

void dfs(int v, int c){
    visited[v] = 1;
    comp[c].push_back(v);
    for(auto a : graph[v]){
        if(!visited[a]) dfs(a, c);
    }
}

signed main(){
    freopen("fenceplan.in", "r", stdin);
    freopen("fenceplan.out", "w", stdout);
    int n, m; cin >> n >> m;
    for(int i = 0; i < n; i++){
        int a, b; cin >> a >> b;
        coord[i].first = a;
        coord[i].second = b;
    }

    for(int i = 0; i < m; i++){
        int a, b; cin >> a >> b;
        a--, b--;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    int c = 0; 
    for(int i = 0; i < n; i++){
        if(!visited[i]){
            c++;
            dfs(i, c);
        }
    }

    int res = INT_MAX;
    for(int i = 1; i <= c; i++){
        int x1 = (1e8)+7, y1 = (1e8)+7, x2 = -1, y2 = -1;
        for(auto b : comp[i]){
            //cout << coord[b].first << " " << coord[b].second << endl;
            x1 = min(coord[b].first, x1);
            y1 = min(coord[b].second, y1);
            x2 = max(coord[b].first, x2);
            y2 = max(coord[b].second, y2);
        }
        //cout << x1 << " " << x2 << " " << y1 << " " << y2 << endl;
        int a = (2*(x2 - x1) + (y2-y1)*2);
        res = min(res, a);
    }

    cout << res << endl;
}