#include <bits/stdc++.h>
using namespace std;

int n, k;
const int MAXN = 102;
int grid[MAXN][11];
int visited[MAXN][11];

int d1[] = {0, 1, 0, -1};
int d2[] = {1, 0, -1, 0};

void dfs(int x, int y){
    visited[x][y] = 1;
    int cnt = 0;
    for(int i = 0; i < 4; i++){
        int nx = x+d1[i];
        int ny = y+d2[i];
        if(nx < 0 || nx > n) continue;
        if(ny < 0 || ny > 10) continue;
        if(grid[nx][ny] == grid[x][y] && !visited[nx][ny]){
            dfs(nx, ny);
            cnt++;

        }
    }

    //return cnt;
}

int main(){
    cin >> n >> k;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < 10; j++){
            cin >> grid[i][j];
        }
    }

    for(int i = 0; i < n; i++){
        for(int j = 0; j < 10; j++){    
        }
    }
}