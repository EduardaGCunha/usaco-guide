#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(0); cin.tie(0)
#define endl "\n"
#define int long long
signed main(){
    fastio;
    int n, k; cin >> n >> k;
    int h[n];
    for(int i = 0; i < n; i++) cin >> h[i];

    vector<int> dp(n, INT_MAX);
    dp[0] = 0;

    for(int i = 1; i < n; i++){
        for(int j = max(0LL, i -k); j < i; j++){
            dp[i] = min(dp[i], dp[j] + abs(h[i] - h[j]));
        }
    }

    cout << dp[n-1] << endl;
}