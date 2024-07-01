#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e3+5;
char grid[MAXN][MAXN];
int visited[MAXN][MAXN];

int n, m;
int d1[] = {0, 1, 0, -1};
int d2[] = {1, 0, -1, 0};

void dfs(int x, int y){
    visited[x][y] = 1;
    for(int i = 0; i < 4; i++){
        if(x+d1[i] < 0 || x+d1[i] > n) continue;
        if(y+d2[i] < 0 || y+d2[i] > m) continue;
        if(grid[x+d1[i]][y+d2[i]] == '.' && !visited[x+d1[i]][y+d2[i]]){
            dfs(x+d1[i], y+d2[i]);
        }
    }
}

int main(){
    cin >> n >> m;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> grid[i][j];
            visited[i][j] = 0;
        }
    }

    int c = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(!visited[i][j] && grid[i][j] == '.'){
                c++;
                dfs(i, j);
                //cout << i << " " << j << endl;
            }
        }
    }

    cout << c << endl;
}