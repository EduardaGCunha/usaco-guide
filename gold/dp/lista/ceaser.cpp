#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define fastio ios_base::sync_with_stdio(0); cin.tie(0)
#define int long long
const int MOD = 1e8;
const int MAXN = 101;
const int MAXK = 11;
int dp[MAXN][MAXN][MAXK][MAXK];
int n1, n2, k1, k2; 

int brute(int a, int b, int segA, int segB){
    if(a == n1 && b == n2) return 1;

    if(dp[a][b][segA][segB] != -1) return dp[a][b][segA][segB];
    
    int ans = 0;
    if(a < n1 && segA < k1){
        ans = (ans + brute(a+1, b, segA+1, 0))%MOD;
    }
    if(b < n2 && segB < k2){
        ans = (ans + brute(a, b+1, 0, segB+1))%MOD;
    }

    return dp[a][b][segA][segB] = ans;
}

signed main(){
    fastio;
    cin >> n1 >> n2 >> k1 >> k2;
    memset(dp, -1, sizeof(dp));
    cout << (brute(0, 0, 0, 0))%MOD<< endl;
}