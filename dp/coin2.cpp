#include <bits/stdc++.h>
using namespace std;

#define int long long
const int MAXN = (1e6)+7;
int dp[MAXN], arr[MAXN];
int n, k;
const int mod = 1000000007;


signed main(){
    cin >> n >> k;
    for(int i = 0; i < n; i++) cin >> arr[i];
    for(int i = 0; i < MAXN; i++) dp[i] = -1;
    dp[0] = 1;
    for(int i = 1; i <= n; i++){
        for(int j = 0; j <= k; j++){
            if(j - arr[i-1] >= 0){
                dp[j] += dp[j - arr[i-1]];
                dp[j] %= mod;
            }
        }
    } 
    cout << dp[k] << endl;
}