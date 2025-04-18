#include <bits/stdc++.h>
using namespace std;

#define int long long
int n, m;
string s, t;

const int MAXN = 1e3+7;
int dp[MAXN][MAXN];

int dist(int x1, int y1, int x2, int y2){
    return (x1-x2)*(x1-x2) + (y1-y2)*(y1-y2);
}

pair<int, int> upd(int x, int y, int idx, string k){
    if(k[idx] == 'N') y += 1;
    else if(k[idx] == 'S') y -= 1;
    else if(k[idx] == 'E') x += 1;
    else if(k[idx] == 'W') x -= 1;
    return {x, y};
}

int brute(int x1, int y1, int idx1, int x2, int y2, int idx2){
    if(idx1 > n || idx2 > m) return INT_MAX;
    if(idx1 == n && idx2 == m) return 0;

    if(dp[idx1][idx2] != -1) return dp[idx1][idx2];
    int ans = INT_MAX; 
    pair<int, int> p1 = upd(x1, y1, idx1, s);
    int d = dist(p1.first, p1.second, x2, y2);
    //cout << d << " ";
    ans = min(brute(p1.first, p1.second, idx1+1, x2, y2, idx2) + d, ans);
    pair<int, int> p2 = upd(x2, y2, idx2, t);
    d = dist(x1, y1, p2.first, p2.second);
    //cout << d << endl;
    ans = min(brute(x1, y1, idx1, p2.first, p2.second, idx2+1) + d, ans);
    d = dist(p1.first, p1.second, p2.first, p2.second);
    ans = min(brute(p1.first, p1.second, idx1+1, p2.first, p2.second, idx2+1) + d, ans);
    //cout << ans << endl;
    return dp[idx1][idx2] = ans;
}

signed main(){
    freopen("radio.in", "r", stdin);
    freopen("radio.out", "w", stdout);
    cin >> n >> m;
    int x1, x2, y1, y2; cin >> x1 >> y1 >> x2 >> y2;
    cin >> s >> t;
    memset(dp, -1, sizeof(dp));
    cout << brute(x1, y1, 0, x2, y2, 0) << endl;
}