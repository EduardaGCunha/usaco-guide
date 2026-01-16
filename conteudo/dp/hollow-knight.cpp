#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(0); cin.tie(0)
#define int long long
#define endl '\n'

const int INF = 1e5;
const int MAXN = 1e3+7;
int dp[2][MAXN][MAXN];
int c[MAXN], p[MAXN];

int n, m;

int pd(int idx, int cost, int used){
    if(cost > m) return -INF;
    if(idx == n) return 0;

    if(dp[used][idx][cost] != -1) return dp[used][idx][cost];

    if(used) dp[used][idx][cost] = max(pd(idx+1,  cost + c[idx], used) + p[idx], pd(idx+1, cost, used));
    else dp[used][idx][cost] = max({pd(idx+1, cost, 1) + p[idx], pd(idx+1, cost + c[idx], 0) + p[idx], pd(idx+1, cost, 0)});

    return dp[used][idx][cost];
}

void solve(){
    cin >> n >> m;
    for(int i = 0; i < MAXN; i++) 
        for(int j = 0; j < MAXN; j++) dp[0][i][j] = -1, dp[1][i][j] = -1;
    for(int i = 0; i < n; i++) cin >> c[i] >> p[i];
    cout << pd(0, 0, 0) << endl;
}

signed main(){
	fastio;
    int t;
    t = 1;
	while(t--){
		solve();
	}
}