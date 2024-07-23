#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e3;
char grid[MAXN][MAXN];
int dist[MAXN][MAXN];
int INF = 1e15;
int d1[] = {0, 1, 0, -1};
int d2[] = {1, 0, -1, 0};

int main(){
    int n, m; cin >> n >> m;
    int sx = -1, sy = -1;
    vector<pair<int, int>> monsters;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> grid[i][j];
            if(grid[i][j] == 'A'){
                sx = i; sy = j;
            }else if(grid[i][j] == 'M'){
                monsters.push_back({i, j});
            }
        }
    }

    queue<pair<int, int>> q;
    q.push({sx, sy});
    dist[sx][sy] = 0;
    while(!q.empty()){
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        for(int i = 0; i < 4; i++){
            int dx = x + d1[i];
            int dy = y + d2[i];
            if(dx < 0 || dx >= n) continue;
            if(dy < 0 || dy >= n) continue;
            if(dist[dx][dy] == INF && grid[dx][dy] != '#'){
                dist[dx][dy] = dist[x][y] + 1;
                q.push({dx, dy});
            }
        }
    }

    
}