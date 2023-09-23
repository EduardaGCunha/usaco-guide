#include <bits/stdc++.h>
using namespace std;

const int mod = 1000000007; 

int main(){
    int n, m;
    cin >> n >> m;
    vector<int> coins(n);
    vector<int> dp(m+1, 0);
    for(int i = 0; i < n; i++) cin >> coins[i];

    dp[0] = 1;
    for(int i : coins){
        for(int j = 1; j <= m; j++){
            if(j - i >= 0){
                dp[j] += dp[j-i];
                dp[j]%=mod;
            }
        }
    }
    cout << dp[m] << endl;
    return 0;
    
}