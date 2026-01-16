#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(0); cin.tie(0)
#define int long long
#define endl '\n'

const int INF = 1e8;
const int MOD = 998244353;

void solve(){
    int n; cin >> n;
    int arr[n];
    int tot = 0;
    for(int i = 0; i < n; i++){
        cin >> arr[i];
        tot += arr[i];
    }

    sort(arr, arr+n);
    vector<int> dp(tot+1, 0);
    dp[0] = 1;
    int ans =0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j <= tot; j++){
            if(dp[j] == 0) continue;
            int g = max(arr[i], (j+arr[i]+1)/2);
            ans = (ans + g*dp[j])%MOD;
        }

        for(int j = tot; j >= arr[i]; j--){
            dp[j] = (dp[j] + dp[j-arr[i]])%MOD;
        }
    }

    cout << ans << endl;
}

signed main(){
	fastio;
    int t;
    //cin >> t;
    t = 1;
	while(t--){
		solve();
	}
}