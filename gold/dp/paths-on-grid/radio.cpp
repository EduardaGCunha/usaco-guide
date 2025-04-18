#include <bits/stdc++.h>
using namespace std;

#define int long long

const int INF = 1e12;
const int MAXN = 1e3+7;
int dp[MAXN][MAXN];

pair<int, int> upd(int x, int y, char a){
    if(a == 'N') y++;
    else if(a == 'S') y--;
    else if(a == 'E') x++;
    else x--;
    return {x, y};
}

int dist(pair<int, int> a, pair<int, int> b){
    auto [x1, y1] = a;
    auto [x2, y2] = b;
    return (x1-x2)*(x1-x2) + (y1-y2)*(y1-y2);
}

signed main(){

    freopen("radio.in", "r", stdin);
    freopen("radio.out", "w", stdout);
    //what if only bessie moves
    //what if only john moves
    //what if both move 

    int n, m; cin >> n >> m;
    pair<int, int> f[n+1], b[m+1];
    cin >> f[0].first >> f[0].second;
    cin >> b[0].first >> b[0].second;
    string s, t; cin >> s >> t;

    for(int i = 1; i <= n; i++){
        f[i] = upd(f[i-1].first, f[i-1].second, s[i-1]);
    }

    for(int i = 1; i <= m; i++){
        b[i] = upd(b[i-1].first, b[i-1].second, t[i-1]);
    }

    for(int i = 0; i <= n; i++){
        for(int j = 0; j <= m; j++){
            dp[i][j] = INF;
        }
    }
    
    dp[0][0] = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            dp[i+1][j] = min(dp[i+1][j], dp[i][j] + dist(f[i+1], b[j]));
            dp[i][j+1] = min(dp[i][j+1], dp[i][j] + dist(f[i], b[j+1]));
            dp[i+1][j+1] = min(dp[i+1][j+1], dp[i][j] + dist(f[i+1], b[j+1]));
        }
    }

    cout << dp[n][m] << endl;
}