#include <bits/stdc++.h>
using namespace std;

const int mod = 1000000007; 

int main(){
    int n;
    cin >> n;
    vector<string> grid(n);
    for(int i = 0; i < n; i++)
        cin >> grid[i];
    vector<vector<long long>> dp(n, vector<long long>(n, 0));
    dp[0][0] = grid[0][0] == '*'? 0 : 1;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(grid[i][j] != '*'){
                if(i-1 >= 0 && grid[i-1][j] != '*'){
                    dp[i][j] = (dp[i][j] + dp[i-1][j])%mod;
                }
                if(j-1 >= 0 && grid[i][j-1] != '*'){
                    dp[i][j] = (dp[i][j] + dp[i][j-1])%mod;
                }
            }
        }
    }

    cout << dp[n-1][n-1] << endl;

}