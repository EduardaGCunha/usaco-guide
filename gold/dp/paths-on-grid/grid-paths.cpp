#include <bits/stdc++.h>
using namespace std;

#define int long long
const int MAXN = 1e3;
const int mod = (1e9)+7;
int n;
int dp[MAXN][MAXN]; 
char grid[MAXN][MAXN];

signed main(){
    //freopen("test1.txt", "r", stdin);
    cin >> n;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++) cin >> grid[i][j];
    }
    dp[0][0] = grid[0][0] == '*'? 0 : 1;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(grid[i][j] == '*') continue;
            if(i - 1 >= 0 && grid[i-1][j] != '*'){
                dp[i][j] += dp[i-1][j];
                dp[i][j] %= mod;
            }if(j - 1 >= 0 && grid[i][j-1] != '*'){
                dp[i][j] += dp[i][j-1];
                dp[i][j] %= mod;
            }
        }
    }
    cout << dp[n-1][n-1] << endl;
}