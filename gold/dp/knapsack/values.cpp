#include <bits/stdc++.h>
using namespace std;

int dp[501][501];

int main(){
    int n, m; cin >> n >> m;
    int arr[n];
    for(int i = 0; i < n; i++) cin >> arr[i];
    
    dp[0][0] = 1;
    for(int i = 0; i < n; i++){
        for(int j = m; j >= arr[i]; j--){
            /* achar uma dp tal que eu consiga alcancar dp[j][k]
            */
            for(int k = j - arr[i]; k >= 0; k--){
                //eh possivel fazer essa subset sum sem a nossa coin atual? ent eh possivel fazer com 
                dp[j][k] |= dp[j-arr[i]][k];
                //adicionando a coin atual a soma de k
                dp[j][k+arr[i]] |= dp[j-arr[i]][k];
            }
        }
    }

    vector<int> ans;
    for(int i = 0; i <= m; i++){
        if(dp[m][i]) ans.push_back(i);
    }

    cout << ans.size() << endl;
    for(auto u : ans) cout << u << " ";
    cout << endl;
}