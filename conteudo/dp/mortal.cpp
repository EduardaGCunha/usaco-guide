#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(0); cin.tie(0)
#define int long long
#define endl '\n'

const int INF = 1e8;

void solve(){
    int n; cin >> n;
    int arr[n];
    for(int i = 0; i < n; i++) cin >> arr[i];

    vector<vector<int>> dp(n, vector<int>(2, INF));
    dp[0][0] = dp[0][1] = arr[0];
    for(int i = 1; i < n; i++){
        if(i - 1 >= 0){
            dp[i][0] = min(dp[i-1][1] + arr[i], dp[i][0]);
            dp[i][1] = min(dp[i-1][0], dp[i][1]);
        }
        if(i - 2 >= 0){
            dp[i][0] = min(dp[i-2][1] + arr[i] + arr[i-1], dp[i][0]);
            dp[i][1] = min(dp[i-2][0], dp[i][1]);
        }
    }

    cout << min(dp[n-1][0], dp[n-1][1]) << endl;
}

signed main(){
	fastio;
    int t; cin >> t;
	while(t--){
		solve();
	}
}