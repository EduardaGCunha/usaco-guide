#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e3+2; 
int grid[MAXN][MAXN];

int main(){
    freopen("paintbarn.in", "r", stdin);
    freopen("paintbarn.out", "w", stdout);
    int n, k; cin >> n >> k;
    for(int i = 0; i < n; i++){
        int a, b, c, d; cin >> a >> b >> c >> d;
        a++, b++, c++, d++;
        grid[a][b]++;
        grid[a][d]--;
        grid[c][d]++;
        grid[c][b]--;
    }

    int cnt = 0;
    for(int i = 1; i < MAXN; i++){
        for(int j = 1; j < MAXN; j++){
            grid[i][j] += grid[i-1][j] + grid[i][j-1] - grid[i-1][j-1];
            if(grid[i][j] == k) cnt++;
        }
    }

    cout << cnt << endl;

}