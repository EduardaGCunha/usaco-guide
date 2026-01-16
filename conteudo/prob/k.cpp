
#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(0); cin.tie(0)
#define int long long
#define endl '\n'

const int MOD = 1e9+7;

int sub(int a, int b){
    return (a-b + MOD)%MOD;
}

signed main(){
	fastio;
    int n, K; cin >> n >> K;
    vector<int> arr(K + 1), sum(K + 1, 0), fat(n+1), dp(K+1); 

    for(int i = 1; i <= K; i++){
        cin >> arr[i];
        sum[i] = sum[i-1] + arr[i];
    }

    fat[0] = 1;
    for(int i = 1; i <= n; i++){
        fat[i] = (fat[i-1] * i) % MOD;
    }

    int ans = 0;
    for(int k = 1; k <= K; k++){
        //si!  
        dp[k] = fat[sum[k]];
        for(int j = 1; j < k; j++){
            int resto = fat[sum[k] - sum[j]];
            dp[k] = sub(dp[k], ((dp[j]*resto)%MOD));
        }
        int res = n - sum[k];
        int v = (dp[k]*fat[res])%MOD;
        ans = (ans + v)%MOD;
    }
    cout << sub(fat[n], ans) << endl;
}