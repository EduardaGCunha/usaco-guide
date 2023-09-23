#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, m;
    cin >> n >> m;
    vector<int> price(n);
    vector<int> pages(n);
    for(int i = 0; i < n; i++) cin >> price[i];
    for(int i = 0; i < n; i++) cin >> pages[i];

    vector<int> dp(m+1);

    for(int i = 0; i < n; i++){
        for(int j = m; j >= price[i]; j--){
            dp[j] = max(dp[j], pages[i] + dp[j - price[i]]);
        }
    }

    cout << dp[m];
}