#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
#define fastio ios_base::sync_with_stdio(0); cin.tie(0)
const int MAXN = 1e3+7;
const int MAXM = 11;
int a[MAXN], b[MAXN], c[MAXN], d[MAXN];
int dp[MAXN][MAXM];

int main(){
    fastio;
    int n, m; cin >> n >> m;
    cin >> c[0] >> d[0];

    for(int i = 1; i <= m; i++){
        cin >> a[i] >> b[i] >> c[i] >> d[i];
    }

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            for(int k = 0; k <= (a[j]/b[j]); k++){
                if(i - c[j]*k >= 0){
                    dp[i][j] = max(dp[i][j], dp[i-c[j]*k][j-1] + d[j]*k);
                }
            }
        }
    }

    int ans = 0;
    for(int i = 0; i <= n; i++){
        ans = max(ans, dp[i][m] + ((n-i)/(c[0]))*d[0]); 
    }
    cout << ans << endl;
}