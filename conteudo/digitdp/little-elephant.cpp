#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(0); cin.tie(0)
#define int long long
#define endl '\n'

const int MOD = 1e9+7; 
int dp[20][2][2][12];

string s;

int pd(int idx, int zr, int t, int str){
    if(idx == s.size())return 0;
    

    if(dp[idx][zr][t][str] != -1) return dp[idx][zr][t][str];

    int limit = t ? (s[idx]-'0'): 9;

    int ans = 0;
    for(int i = 0; i <= limit; i++){
        int newt = t && (i == limit);
        if(zr && i == 0){
            ans += pd(idx+1, 1, newt, 0);
        }else{
            int newstr = zr? i : str;
            if(idx == s.size()-1 && newstr == i){
                ans++;
            }else{
                ans += pd(idx+1, 0, newt, newstr);
            }
        }
    }

    return dp[idx][zr][t][str] = ans;
}

int helper(int n){
    memset(dp, -1, sizeof(dp));
    s = to_string(n);
    return pd(0, 1, 1, 0);
}

void solve(){
    int a, b; cin >> a >> b;
    //cout << helper(b) << " " << helper(a) << endl;
    cout << helper(b) - helper(a-1) << endl;
}

signed main(){
	fastio;
    int t=1;
	while(t--){
		solve();
	}
}