#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e5+7;
const int MAXM = 101;
int dp[MAXN][MAXM];
const int mod = 1e9+7;

int main(){
    int n, m; cin >> n >> m;
    int arr[n+1];
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }

    if(arr[0]) dp[0][arr[0]] = 1;
    else{
        for(int i = 1; i <= m; i++){
            dp[0][i] = 1;
        }
    }
    
    //pos, val
    for(int i = 1; i < n; i++){
        if(arr[i]){
            dp[i][arr[i]] = (dp[i][arr[i]] + dp[i-1][arr[i]])%mod;
            if(arr[i]-1 >= 1)
                dp[i][arr[i]] = (dp[i][arr[i]] + dp[i-1][arr[i]-1])%mod;
            if(arr[i]+1 <= m){
                dp[i][arr[i]] = (dp[i][arr[i]] + dp[i-1][arr[i]+1])%mod;
            }
        }else{
            for(int j = 1; j <= m; j++){
                dp[i][j] = (dp[i][j] + dp[i-1][j])%mod;
                if(j-1 >= 1) 
                    dp[i][j] = (dp[i][j] + dp[i-1][j-1])%mod;
                if (j+1 <=m) 
                    dp[i][j] = (dp[i][j] + dp[i-1][j+1])%mod;
            }
        }
    }

    int ans = 0;
    for(int i = 1; i <= m; i++){
        ans = (ans + dp[n-1][i])%mod;
    }
    cout << ans << endl;
}