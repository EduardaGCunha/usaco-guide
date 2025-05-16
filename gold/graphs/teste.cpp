#include <bits/stdc++.h>
using namespace std;
 
#define fastio ios_base::sync_with_stdio(0); cin.tie(0)
#define int long long
#define endl "\n"
 
const int MAXN = 1e6+7;
const int MOD = 1e9+7;
int fact[MAXN], inv[MAXN];
 
int fastexpo(int a, int b){
    int res = 1;
    while(b > 0){
        if(b&1) res = (res*a)%MOD;
        a = (a*a)%MOD;
        b/=2;
    }
    return res;
}
 
void fat(){
    fact[0] = 1;
    inv[0] = 1;
    for(int i = 1; i <= MAXN; i++){
        fact[i] = (fact[i-1]*i)%MOD;
        inv[i] = fastexpo(fact[i], MOD-2);
    }
}
 
signed main(){
    fastio;
    fat();
    string s; cin >> s;
    map<char, int> mp;
    for(int i = 0; i < s.size(); i++){
        mp[s[i]]++;
    }
 
    int res = 1;
    for(auto u : mp){
        res  = (res*u.second)%MOD;
    }
 
    //cout << res << endl;
    //cout << s.size() << endl;
    cout << (fact[s.size()]*inv[res])%MOD << endl;
}