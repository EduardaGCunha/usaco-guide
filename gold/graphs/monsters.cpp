#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e3;
char grid[MAXN][MAXN];
int d1[] = {0, 1, -1, 0};
int d2[] = {1, 0, 0, -1};

int main(){
    int n, m; cin >> n >> m;
    queue<pair<int, int>> q;
    pair<int, int> s, e;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> grid[i][j];
            if(grid[i][j] == 'A'){
                s = {i, j};
            }else if(grid[i][j] == 'M'){
                q.push({i, j});
            }
        }
    }

    q.push(s);
    while(!q.empty()){
        auto [x, y] = q.front(); q.pop();
        if(grid[x+1][y] == '.' && x+1 < n){
            grid[x+1][y] = (grid[x][y] == 'M') ? 'M' : 'D';
            q.push({x+1, y});
        }
        if(grid[x-1][y] == '.' && x-1 >= 0){
             grid[x-1][y] = (grid[x][y] == 'M') ? 'M' : 'U';
            q.push({x-1, y});
        }
        if(grid[x][y+1] == '.' && y+1 < m){
            grid[x][y+1] = (grid[x][y] == 'M') ? 'M' : 'R';
            q.push({x, y+1});
        }
        if(grid[x][y-1] == '.' && y-1 >= 0){
            grid[x][y-1] = (grid[x][y] == 'M') ? 'M' : 'L';
            q.push({x, y-1});
        }
    }

    e = {-1, -1};
    for(int i = 0; i < n; i++){
        if(grid[i][0] != 'M' && grid[i][0] != '.' && grid[i][0] != '#'){
            e.second = 0;
            e.first = i;

        }
        if(grid[i][m-1] != 'M' && grid[i][m-1] != '.' && grid[i][m-1] != '#'){
            e.second = m-1;
            e.first = i;
        }
    }

    for(int i = 0; i < m; i++){
        if(grid[0][i] != 'M' && grid[0][i] != '.' && grid[0][i] != '#'){
            e.first = 0;
            e.second = i;
        }
        if(grid[n-1][i] != 'M' && grid[n-1][i] != '.' && grid[n-1][i] != '#'){
            e.first = n-1;
            e.second = i;
        }
    }

    if(e.first == -1 || e.second == -1){
        cout << "NO" << endl;
        return 0;
    }
    cout << "YES" << endl;
    string ans;
    auto [x,y] = e;
    while(grid[x][y] != 'A'){
        ans += grid[x][y];
        if(grid[x][y] == 'R') y--;
        else if(grid[x][y] == 'L') y++;
        else if(grid[x][y] == 'D') x--;
        else x++;
    }
    cout << ans.length() << endl;
    for(int i = ans.length()-1; i >= 0; i--){
        cout << ans[i];
    }
    cout << endl;
}