#include <bits/stdc++.h>
using namespace std;
 
int n, m, x, y, a, b;
 
const int MAXN = 1e2+1;
int grid[MAXN][MAXN];
int visited[MAXN][MAXN];
int d1[] = {0, 1, 0, -1};
int d2[] = {1, 0, -1, 0};
 
bool bfs(int mask){
    memset(visited, 0, sizeof(visited));
    if(!(mask & (1 << grid[a][b]-1))) return 0;
    queue<tuple<int, int>> q;
    q.push({a, b});
    visited[a][b] = 1;
    while(!q.empty()){
        auto [u, v] = q.front(); q.pop();
        for(int i = 0; i < 4; i++){
            int dx = u + d1[i];
            int dy = v + d2[i];
 
            if(dx < 0 || dx >= n) continue;
            if(dy < 0 || dy >= m) continue;
            if(!visited[dx][dy] && (mask & (1<<(grid[dx][dy]-1)))){
                visited[dx][dy] = 1;
                q.push({dx, dy});
            }
        }
 
        if(u == x && v == y) return 1;
    }
 
    return 0;
}
 
int main(){
    cin >> n >> m >> a >> b >> x >> y;
    a--, b--;
    x--, y--;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> grid[i][j];
        }
    }
 
    int ans = 11;
    for(int i = 0; i < (1<<10); i++){
        if(bfs(i)) ans = min(ans, __builtin_popcount(i));
    }
 
    cout << ans << endl;
}