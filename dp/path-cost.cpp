#include <bits/stdc++.h>
using namespace std;

int main(){
    const int n = 8;
    int grid[n][n], dp[n][n];
    
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> grid[i][j];
        }
    }

    // for(int i = n; i >= 0; i--){
    //     for(int j = 0; j < n - 1; j++){
    //         dp[i][j] = max({dp[i-1][j], dp[i][j+1], dp[i-1][j-1]}) + grid[i][j];
    //     }
    // }

    // cout << dp[n-1][0] << endl;
}