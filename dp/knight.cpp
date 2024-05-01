#include <bits/stdc++.h>
using namespace std;

#define int long long
const int MAXN = 1e3;
int n, m; 
int dp[MAXN][MAXN];


signed main(){
    freopen("knight.in", "r", stdin);
    freopen("knight.out", "w", stdout);

    cin >> n >> m;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            dp[i][j] = 0;
        }
    }
    dp[0][0] = 1;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(i-1 >= 0 && j - 2 >= 0){
                dp[i][j] += dp[i-1][j-2];
            }
            if(i-2 >= 0 && j - 1 >= 0){
                dp[i][j] += dp[i-2][j-1];
            }
        }
    }
    cout << dp[n-1][m-1] << endl;
}