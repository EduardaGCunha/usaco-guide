#include <bits/stdc++.h>
using namespace std;

const int mod = 1000000007; 
int n, m;

int main(){
    int n, m;
    cin >> n >> m;
    vector<int> coins(n);
    vector<int> dp(m+1, -1);
    for(int i = 0; i < n; i++) cin >> coins[i];

    dp[0] = 1;
    for(int i = 1; i <= m; i++){
        dp[i] = 0;
        
        for(int j = 0; j < n; j++){
            if(i - coins[j] >= 0){
                dp[i] = (dp[i] + dp[i-coins[j]])%mod;
            }
        }
    }

    cout <<dp[m] << endl;
    return 0;
    
}