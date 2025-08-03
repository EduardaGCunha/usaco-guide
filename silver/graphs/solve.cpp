#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(0); cin.tie(0)
#define int long long
#define endl '\n'

int d1[] = {0, 1, 0, -1};
int d2[] = {1, 0, -1, 0};
int n, m;

void solve(){
    cin >> n >> m;
    //cout << n << " " << m << endl;
    vector<vector<char>> grid(n, vector<char>(m));
    vector<pair<int, int>> g, b;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> grid[i][j];
            if(grid[i][j] == 'G') g.push_back({i, j});
            else if(grid[i][j] == 'B') b.push_back({i, j});
        }
    }

    for(auto [x, y]: b){
        for(int i = 0; i < 4; i++){
            int dx = x+d1[i];
            int dy = y+d2[i];
            if(dx < 0 || dx >= n) continue;
            if(dy < 0 || dy >= m) continue;
            if(grid[dx][dy] == '.'){
                grid[dx][dy] = '#';
            }
        } 
    }
    
    //cout << grid[n-1][m-1] << endl;
    if(grid[n-1][m-1] == '#'){
        if(g.empty()){
            cout << "Yes\n";
            return;
        }else{
            cout << "No\n";
            return;
        }
    }
    
    queue<pair<int, int>> q;
    vector<vector<int>> visited(n, vector<int>(m, 0));
    q.push({n-1, m-1});
    visited[n-1][m-1] = 1;
    while(!q.empty()){
        auto [x, y] = q.front(); q.pop();
        for(int i = 0; i < 4; i++){
            int dx = x+d1[i];
            int dy = y+d2[i];
            if(dx < 0 || dx >= n) continue;
            if(dy < 0 || dy >= m) continue;
            if((grid[dx][dy] != '#') && !visited[dx][dy]){
                visited[dx][dy] = 1;
                q.push({dx, dy});
            }
        } 
    }

    if(!b.empty()){
        for(auto [x, y] : b){
            if(visited[x][y]){
                cout << "No\n";
                return;
            }
        }
    }

    if(!g.empty()){
        for(auto [x, y] : g){
            if(!visited[x][y]){
                cout << "No\n";
                return;
            }
        }
    }

    cout << "Yes\n";
}

signed main(){
	fastio;
	int t; cin >> t;
	while(t--){
		solve();
	}
}