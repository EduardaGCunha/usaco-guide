#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(0); cin.tie(0)
#define endl "\n"
#define int long long

int dist(pair<int, int> a, pair<int, int> b){
    return (a.first - b.first)*(a.first - b.first) + (a.second-b.second)*(a.second-b.second);
}

signed main(){
    fastio;
    freopen("checklist.in", "r", stdin);
    freopen("checklist.out", "w", stdout);
    int h, g; cin >> h >> g;
    pair<int, int> H[h], G[g];
    for(int i = 0; i < h; i++) cin >> H[i].first >> H[i].second;
    for(int i = 0; i < g; i++) cin >> G[i].first >> G[i].second;

    vector<vector<vector<int>>> dp(h+1, vector<vector<int>>(g+1, vector<int>(2, 1e18)));

    dp[1][0][0] = 0;
    for(int i = 0; i <= h; i++){
        for(int j = 0; j <= g; j++){
            if(i > 1){//H->H
                dp[i][j][0] = min(dp[i][j][0], dp[i-1][j][0] + dist(H[i-2], H[i-1]));
            }
            if(j > 1){//G->G
                dp[i][j][1] = min(dp[i][j][1], dp[i][j-1][1] + dist(G[j-2], G[j-1]));
            }
            if(i > 0 && j > 0){
                //H -> G
                dp[i][j][0] = min(dp[i][j][0], dp[i-1][j][1] + dist(G[j-1], H[i-1]));
                //G->H
                dp[i][j][1] = min(dp[i][j][1], dp[i][j-1][0] + dist(G[j-1], H[i-1]));
            }
        }
    }

    cout << dp[h][g][0] << endl;

}