#include <bits/stdc++.h>
using namespace std;

const int mod = 1000000007; 
int n, m;

int pd(int x, vector<int> &c, vector<int> &dp){
    if(x==0) return 1;
    if(x < 0) return 0;

    if(dp[x] != -1) return dp[x]; 

    int ans = 0;
    for(int i = 0; i < n; i++){
        ans += pd(x-c[i], c, dp);
        ans %=mod;
    }
    return dp[x] = ans;
}


int main(){
    cin >> n >> m;
    vector<int> coins(n);
    vector<int> dp(m+1, -1);
    for(int i = 0; i < n; i++) cin >> coins[i];

    cout << pd(m, coins, dp);
    return 0;
    
}