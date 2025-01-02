#include <bits/stdc++.h>
using namespace std;

const int MOD = 998244353;

int main(){
    int q, k; cin >> q >> k;
    vector<int> dp(k+1, 0);
    dp[0] = 1;
    while(q--){
        char a; int b; cin >> a >> b;
        if(a == '+') {
            for(int i = k; i >= b; i--){
                dp[i] = (dp[i] + dp[i-b])%MOD;
            }
        }
        else {
            for(int i = b; i <= k; i++){
                dp[i] = (dp[i]- dp[i-b] + MOD)%MOD;
            }
        }
        
        cout << dp[k] << endl;
    }
}