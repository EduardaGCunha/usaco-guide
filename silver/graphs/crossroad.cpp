#include <bits/stdc++.h>
using namespace std;

int n, k, r;

const int MAXN = 102;

vector<pair<int, int>> c;
vector<pair<int, int>> grid[MAXN][MAXN];
int cows[MAXN][MAXN];
void dfs(int x, int y){

}

int main(){
    cin >> n >> k >> r;
    for(int i = 0; i < r; i++){
        int a, b, x, y; 
        cin >> a >> b >> x >> y;
        a--, b--, x--, y--;
        grid[a][b].push_back({x, y});
    }

    for(int i = 0; i < n; i++){
        int a, b; cin >> a >> b;
        a--, b--;
        cows[a][b] = 1;
        c.push_back({a, b});
    }
}