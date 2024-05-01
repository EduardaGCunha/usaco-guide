#include <bits/stdc++.h>
using namespace std;

#define int long long 
const int mod = (1e9)+7;
const int MAXN = (1e6)+7;
int n, m;
int dp[MAXN], coins[MAXN];

signed main(){
    cin >> n >> m;
    for(int i = 0; i < n; i++) cin >> coins[i];
    for(int i = 0; i <= m; i++) dp[i] = 0;
    dp[0] = 1;
    for(int i = 0; i < n; i++){
        for(int j = 0; j <= m; j++){
            if(j - coins[i] >= 0){
                dp[j] += dp[j-coins[i]];
                dp[j] %= mod;
            }
        }
    }
    cout << dp[m] << endl;
}