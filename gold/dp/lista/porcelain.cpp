#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
#define fastio ios_base::sync_with_stdio(0); cin.tie(0)
#define int long long

const int MAXN = 1e4+7;
const int MAXM = 107;
int n, m;
int dp[MAXN][MAXM], value[MAXN][MAXM];
vector<vector<int>> grid;
int pd(int i, int k){
    if (i == n) {
        if (k == m) return 0;
        else return INT_MIN;
    }
    if(dp[i][k] != -1) return dp[i][k];
 
    int ans = 0;
    for (int j = 0; j <= min((int)grid[i].size(), m-k); j++){
        ans = max(ans, pd(i+1, k+j) + value[i][j]);
    }
 
    return dp[i][k] = ans;
}

signed main(){
    fastio;
    cin >> n >> m;
    grid.resize(n);
    vector<int> amount(n);
    for(int i = 0; i < n; i++){
        int x; cin >> x;
        amount[i] = x;
        grid[i].resize(x);
        for(int j = 0; j < x; j++){
            cin >> grid[i][j];
        }
    }

    for(int i = 0; i < n; i++){
        int k = amount[i];
        vector<int> pfx(k + 1, 0), sfx(k+1, 0);
        for (int j = 1; j <= k; j++){
            pfx[j] = grid[i][j-1] + pfx[j-1];
        }
        for (int j = 1; j <= k; j++){
            sfx[j] = grid[i][k-j] + sfx[j-1];
        }
 
        for (int j = 0; j <= k; j++){
            int val = 0;
            for (int r = 0; r <= j; r++){
                int cur = pfx[r] + sfx[j-r];
                val = max(val,cur);
            }
            value[i][j] = val;
        }
    }

    // for(int i = 0; i < n; i++){
    //     for(int j = 0; j < 4; j++){
    //         cout << val[i][j] << " ";
    //     }
    //     cout << endl;
    // }

    memset(dp, -1, sizeof(dp));
    cout << pd(0, 0) << endl;
    

}