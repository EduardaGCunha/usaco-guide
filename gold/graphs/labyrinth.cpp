#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(0); cin.tie(0)
#define int long long
const int MAXN = 1e3;
char grid[MAXN][MAXN], mov[MAXN][MAXN];
int dist[MAXN][MAXN];
pair<int, int> parent[MAXN][MAXN];
int n, m; 
int d1[] = {0, 1, 0, -1};
int d2[] = {1, 0, -1, 0};
char c1[] = {'R', 'D', 'L', 'U'};
int max_dist = 1e15;

signed main(){
    fastio;
    //freopen("test_input.txt", "r", stdin);
    cin >> n >> m;
    int sx= -1, sy=-1, ex=-1, ey=-1;

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> grid[i][j];
            if(grid[i][j] == 'A'){
                sx = i; sy = j;
            }else if(grid[i][j] == 'B'){
                ex = i, ey = j;
            }
            dist[i][j] = max_dist;
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
            if(dy < 0 || dy >= m) continue;
            if(grid[dx][dy] != '#' && dist[dx][dy] == max_dist){
                dist[dx][dy] = dist[x][y] + 1;
                q.push({dx, dy});
                parent[dx][dy] = {x, y};
                mov[dx][dy] = c1[i];
            }
        }
    }

    if(dist[ex][ey] == max_dist) cout << "NO" << endl;
    else{
        cout << "YES" << endl;
        cout << dist[ex][ey] <<  endl;
        pair<int, int> cur = {ex, ey};
        vector<char> res;
        while(cur.first != sx || cur.second != sy){
            res.push_back(mov[cur.first][cur.second]);
            cur = parent[cur.first][cur.second];
        }

        for(int i = res.size()-1; i >= 0; i--){
            cout << res[i];
        }
        cout << endl;
    }
}