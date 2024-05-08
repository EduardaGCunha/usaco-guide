#include <bits/stdc++.h>
using namespace std;

#define int long long

signed main(){
    freopen("king2.in", "r", stdin);
    freopen("king2.out", "w", stdout);
    const int n = 8;
    int dp[n][n];
    
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> dp[i][j];
        }
    }

    //dp[0][n] = grid[0][n];
    for(int i = n - 1; i >= 0; i--){
        for(int j = 0; j < n; j++){
            if(j == 0 && i == n - 1) continue;
            int sum = 1e18;
            if(i < n - 1) sum = min(sum, dp[i+1][j]);
            if(j > 0) sum = min(sum, dp[i][j-1]);
            if(i < n - 1 && j > 0) sum = min(sum, dp[i+1][j-1]);
            dp[i][j] += sum;
        }
    }

    // for(int i = 0; i < n; i++){
    //     for(int j = 0; j < n; j++){
    //         cout << dp[i][j] << " ";
    //     }
    //     cout << endl;
    // }

    cout << dp[0][7] << endl;
}