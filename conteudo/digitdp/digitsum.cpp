#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(0); cin.tie(0)
#define int long long
#define endl '\n'

const int MOD = 1e9+7; 
int dp[10001][2][100];

string r;
int d;

int pd(int idx, int tight, int sum){
    if(idx == r.length()){
        return (sum == 0);
    }

    if(dp[idx][tight][sum] != -1){
        return dp[idx][tight][sum];
    }

    int limit = tight ? (r[idx] - '0') : 9;

    int ans = 0;
    for(int i = 0; i <= limit; i++){
        int new_tight = (tight && (i == limit));
        ans = (ans + pd(idx + 1, new_tight, ((sum + i)%d)))%MOD;
    }
    return dp[idx][tight][sum] = ans;
}

void solve(){
    memset(dp, -1, sizeof(dp));
    cin >> r >> d;
    int ans = pd(0, 1, 0);
    cout << (ans - 1 + MOD)%MOD << endl;
}

signed main(){
	fastio;
    int t=1;
	while(t--){
		solve();
	}
}