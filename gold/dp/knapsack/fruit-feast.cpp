#include <bits/stdc++.h>
using namespace std;

int main(){
    freopen("feast.in", "r", stdin);
    freopen("feast.out", "w", stdout);
    int n, a, b; cin >> n >>  a >> b;
    vector<vector<int>> dp(n+1, vector<int>(2, 0));

    dp[0][0] = 1;
    for(int i = 1; i <= n; i++){
        if(i - a >= 0) dp[i][0] |= dp[i-a][0];
        if(i - b >= 0) dp[i][0] |= dp[i-b][0];
        dp[i/2][1] |= dp[i][0];
    }

    for(int i = 1; i <= n; i++){
        if(i - a >= 0) dp[i][1] |= dp[i-a][1];
        if(i - b >= 0) dp[i][1] |= dp[i-b][1];
    }

    for(int i = n; i>= 0; i--){
        if(dp[i][1] || dp[i][0]){
            cout << i << endl;
            return 0;
        }
    }
}