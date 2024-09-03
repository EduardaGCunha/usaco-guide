#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e5;
int mod = 1e9+7;
int dp[MAXN];

#define int long long

int fibonnaci(int n){
    if(n == 0) return 0;
    if(n == 1) return 1;  

    if(dp[n]) return dp[n]%mod;

    //cout << n << endl; 
    return dp[n] = fibonnaci(n-1) + fibonnaci(n-2);
}

signed main(){
    int n; cin >> n;
    cout << fibonnaci(n) << endl;

}