#include <bits/stdc++.h>
using namespace std;

#define int long long
const int MAXN = 1e6;
int n, m;
int dp[MAXN], cost[MAXN], val[MAXN];

signed main(){
    cin >> n >> m;
    for(int i = 0; i < n; i++) cin >> cost[i];
    for(int i = 0; i < n; i++) cin >> val[i];
    for(int i = 0; i < m; i++) dp[i] = 0;
    for(int i = 0; i < n; i++){
        for(int j = m; j >= cost[i]; j--){
            dp[j] = max(dp[j], val[i] + dp[j-cost[i]]);
        }
    }
    cout << dp[m] << endl;
}