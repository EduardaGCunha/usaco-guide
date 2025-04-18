#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
#define fastio ios_base::sync_with_stdio(0); cin.tie(0)
#define int long long

const int INF = 1e18;
const int MAXN = 110;
const int MAXV = 1e5+7;
int dp[MAXN][MAXV];
int n, W;
int arr[MAXN], weights[MAXN];

int pd(int i, int val){
    if(val < 0) return INF;
    if(val == 0) return 0;
    if(i == 0) return INF;

    if(dp[i][val] != -1) return dp[i][val];

    return dp[i][val] = min(pd(i-1, val - arr[i]) + weights[i], pd(i-1, val));
}

signed main(){
    fastio;
    cin >> n >> W;
    memset(dp, -1, sizeof(dp));
    int maximum = 0;
    for(int i = 1; i <= n; i++){
        cin >> weights[i] >> arr[i];
        maximum += arr[i];
    }

    for(int i = maximum; i >= 0; i--){
        if(pd(n, i) <= W){
            cout << i << endl;
            return 0;
        }
    }
}