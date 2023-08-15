#include <bits/stdc++.h>
using namespace std;

// const int INF= 0x3f3f3f3f;
// int n, m;

// int dp(int m, int ind){
//     if(m < 0) return -INF;
//     if(ind == n) return 0;

//     int &pdm = memo[ind][m];
//     if(pdm != -1) return pdm;

//     return pdm = max(dp(m - price[ind], ind+1) + pages[ind], dp(m, ind+1));
// }


int main(){
    int n, m;
    cin >> n >> m;
    vector<int> price(n);
    vector<int> pages(n);
    for(int i = 0; i < n; i++) cin >> price[i];

    for(int i = 0; i < n; i++) cin >> pages[i];

    vector<vector<int>> dp(n+1, vector<int>(n+1, 0));
    for(int i = 0; i < n; i++){
        for(int j = 0; j <= m; j++){
            dp[i+1][j] = dp[i][j];
            if(j >= price[i]){
                dp[i+1][j] = max(dp[i+1][j], pages[i] + dp[i][j-price[i]]);
            }
        }
    }

    cout << dp[n][m] << endl;
    
}