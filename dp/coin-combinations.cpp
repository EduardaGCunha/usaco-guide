#include <bits/stdc++.h>
using namespace std;

#define int long long
const int MAXN = (1e6)+7;
int dp[MAXN], arr[MAXN];
int n, k;
const int mod = 1000000007;

int pd(int x){
    if(x == 0) return 1;
    if(x < 0) return 0;
    if(dp[x] != -1) return dp[x];
    int ans = 0;
    for(int i = 0; i < n; i++){
        ans+= pd(x - arr[i]);
        ans%= mod;
    }
    return dp[x] = ans;
}

signed main(){
    cin >> n >> k;
    for(int i = 0; i < n; i++) cin >> arr[i];
    for(int i = 0; i < MAXN; i++) dp[i] = -1;
    cout << pd(k) << endl; 
}