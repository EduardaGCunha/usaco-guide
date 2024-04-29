#include <bits/stdc++.h>
using namespace std;

#define int long long
const int MAXN = 1e5;
int n; 
int dp[MAXN];

int pd(int x){
    if(x == n) return 1;
    if(x > n) return 0;
    if(dp[x] != -1) return dp[x];
    for(int i = 1; i <= 6; i++){
        dp[x] += pd(x+i);
    }
    return dp[x];
}

signed main(){
    cin >> n;
    for(int i = 0; i < 1e5; i++) dp[i] = -1;
    cout << pd(0) << endl;
}