#include <bits/stdc++.h>
using namespace std;

#define int long long
const int MAXN = 1e5;
int n;
string s;
int dp[MAXN];

int dynamic(int i){
    if(i >= n) return dp[i] = INT_MIN;
    if(s[i] == 'w') return dp[i] = INT_MIN;
    if(i == n-1) return 0;
    if(dp[i] != -1) return dp[i];
    dp[i] = max({dynamic(i+1) + (s[i] == '"'), dynamic(i+3) +  (s[i] == '"'), dynamic(i+5)+(s[i] == '"')});
    return dp[i];
}

signed main(){
    freopen("lepus.in", "r", stdin);
    freopen("lepus.out", "w", stdout);
    cin >> n;    
    cin >> s;
    for(int i = 0; i < 1e5; i++) dp[i] = -1;
    int a = dynamic(0);
    if(a < 0) cout << -1 << endl;
    else cout << a << endl;
}