#include <bits/stdc++.h>
using namespace std;

#define int long long

int n, m;
const int MAXN = 500;
vector<pair<int, int>> w; 

int grid[MAXN][MAXN];

int d1[] = {1, 0, -1, 0};
int d2[] = {0, 1, 0, -1};

bool check(int mid){
    vector<vector<bool>> visited(n, vector<bool>(m));
    queue<pair<int, int>> q;
    q.push({w[0].first, w[0].second});
    visited[w[0].first][w[0].second] = 1;

    while(!q.empty()){
        int x = q.front().first, y = q.front().second;
        q.pop();
        for(int i = 0; i < 4; i++){
            int nx = x+d1[i];
            int ny = y+d2[i];
            if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
            if(abs(grid[x][y] - grid[nx][ny]) <= mid && !visited[nx][ny]){
                q.push({nx, ny});
                visited[nx][ny] = 1;
            }
        }
    }

    for(auto a : w){
        if(!visited[a.first][a.second]) return false;
    }
    return true;
}

signed main(){
    freopen("ccski.in", "r", stdin);
    freopen("ccski.out", "w", stdout);
    cin >> n >> m;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> grid[i][j];
        }
    }

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            int a; cin >> a;
            if(a){
                w.push_back({i, j});
            }
        }
    }

    int l = 0, r = INT32_MAX;
    while(l < r){
        int mid = (l+r)/2;
        if(check(mid)) r = mid;
        else l = mid+1;
    }

    cout << l << endl;
}