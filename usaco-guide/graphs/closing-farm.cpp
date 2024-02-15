#include <bits/stdc++.h>
using namespace std;

const int MAXN = 3005;
vector<int> graph[MAXN];
int visited[MAXN], closed[MAXN];
int n, m, k, ans = 0;

void dfs(int v){
    visited[v] = 1;
    for(auto a : graph[v]){
        if(visited[a] == 0 && closed[a] == 0) dfs(a);
    }
}

void comp(){
    ans = 0;
    for(int i = 1; i <= n; i++){
        if(visited[i] == 0 && closed[i] == 0){
            dfs(i);
            ans++;
        }
    }
    if(ans > 1) cout << "NO" << endl;
    else cout << "YES" << endl;
}

int main(){
    freopen("closing.in", "r", stdin);
    freopen("closing.out", "w", stdout);
    cin >> n >> m;
    for(int i = 0; i < m; i++){
        int a, b; cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    for(int i = 0; i < n; i++){
        comp();
        cin >> k;
        closed[k] = 1;
        for(int i = 1; i <= n; i++) visited[i] = 0;
    }
}