#include <bits/stdc++.h>
using namespace std;

const int MAXN = 107;
vector<pair<int, int>> grid[MAXN][MAXN];
int visited[MAXN][MAXN], lit[MAXN][MAXN];
int cnt = 1;
int n, m;

int d1[] = {0, 1, 0, -1};
int d2[] = {1, 0, -1, 0};

void dfs(int x, int y){
    if(!lit[x][y] || visited[x][y] || x < 1 || x > n || y < 1 || y > n) return;
    visited[x][y] = 1;
    for(auto [u, v]: grid[x][y]){
        if(!lit[u][v]){
            lit[u][v] = 1;
            cnt++;
        }
        if(visited[u][v-1] || visited[u-1][v] || visited[u+1][v] || visited[u][v+1]){
            dfs(u, v);
        }
    }

    dfs(x, y+1);
    dfs(x-1, y);
    dfs(x+1, y);
    dfs(x, y-1);

}

int main(){
    freopen("lightson.in", "r", stdin);
    freopen("lightson.out", "w", stdout);
    cin >> n >> m;
    for(int i = 0; i < m; i++){
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        grid[a][b].push_back({c, d});
    }

    lit[1][1]= 1;
    dfs(1,1);
    cout << cnt << endl;

}