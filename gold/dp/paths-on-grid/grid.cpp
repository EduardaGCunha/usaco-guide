#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
#define fastio ios_base::sync_with_stdio(0); cin.tie(0)

const int MOD = 1e9+7;
const int MAXN = 1000;
char grid[MAXN][MAXN];
int dp[MAXN][MAXN];
int main(){
    fastio;
    int n, m; cin >> n >> m;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> grid[i][j];
        }
    }

    dp[0][0] = 1;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(i-1 >= 0 && grid[i-1][j] == '.') dp[i][j] = (dp[i][j] + dp[i-1][j])%MOD;
            if(j-1 >= 0 && grid[i][j-1] == '.') dp[i][j] = (dp[i][j] + dp[i][j-1])%MOD;
        }
    }

    cout << (dp[n-1][m-1]%MOD) << endl;
}