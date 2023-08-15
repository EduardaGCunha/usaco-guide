#include <bits/stdc++.h>
using namespace std;

int n;

int solve(int m, vector<int> &coins, vector<int> &dp){
    if(m < 0) return -1;
    if(m == 0) return 0;

    if(dp[m] != -2) return dp[m];

    int ans = INT_MAX;
    for(int i = 0; i < n; i++){
        int val = solve(m-coins[i], coins, dp);
        if(val != -1) ans = min(ans, val+1);
    }

    if(ans == INT_MAX) ans = -1;
    return dp[m] = ans;
}


int main(){
    int m;
    cin >> n >> m;

    vector<int> coins(n);
    for(int i = 0; i < n; i++){
        cin >> coins[i];
    }

    vector<int> dp(m+1, -2);

    cout << solve(m, coins, dp);

}