#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e3+7;
char grid[MAXN][MAXN];
int visited[MAXN][MAXN]; 

int n;
int d1[] = {0, 1, 0, -1};
int d2[] = {1, 0, -1, 0};
int a, p;

void dfs(int x, int y){
    if(x < 0 || x >= n || y < 0 || y >= n){
        p++;
        return;
    }
    if(visited[x][y]) return;
    if(grid[x][y] == '.'){
        p++;
        return;
    }
    visited[x][y] = 1;
    if(grid[x][y] == '#') a++;
    dfs(x-1, y);
    dfs(x+1, y);
    dfs(x, y+1);
    dfs(x, y-1);
}

int main(){
    freopen("perimeter.in", "r", stdin);
    freopen("perimeter.out", "w", stdout);
    cin >> n;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> grid[i][j];
        }
    }

    vector<pair<int, int>> res;
    for(int i = 0; i < n; i++){
        int ans = 0;
        for(int j = 0; j < n; j++){
            if(grid[i][j] == '#' && !visited[i][j]){
                a = 0, p = 0;
                dfs(i, j);
                res.push_back({a, -p});
            }
        }
    }

    sort(res.rbegin(), res.rend());

    cout << res[0].first << " " << -1*res[0].second << endl;
    
}