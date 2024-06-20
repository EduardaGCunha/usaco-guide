#include <bits/stdc++.h>
using namespace std;

#define int long long
const int MAXN = (1e6)+7;
int n; 
int dp[MAXN];
const int mod = 1000000007;

int pd(int x){
    if(x == 0) return 1;
    if(x < 0) return 0;
    if(dp[x] != -1) return dp[x];
    int ans = 0;
    for(int i = 1; i <= 6; i++){
        ans += pd(x-i);
        ans %= mod;
    }
    return dp[x] = ans;
}

signed main(){
    cin >> n;
    for(int i = 0; i < (1e6)+7; i++) dp[i] = -1;
    cout << pd(n) << endl;
    
}