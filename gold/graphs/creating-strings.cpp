#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(0); cin.tie(0)
#define int long long
#define endl "\n"

const int MAXN = 1e6+7;
const int MOD = 1e9+7;
int fact[MAXN], inv[MAXN];

#if defined(DEBUG)
    #define _ (void)0
    #define debug(x) cout << __LINE__ << ": " << #x << " = " << x << ln
#else
    #define _ ios_base::sync_with_stdio(false), cin.tie(NULL)
    #define debug(x) (void)0
#endif
 

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
    for(int i = 1; i < MAXN; i++){
        fact[i] = (fact[i-1]*i)%MOD;
        inv[i] = (fastexpo(fact[i], MOD-2))%MOD;
    }
}

signed main(){
    fastio;
    fat();
    string s; cin >> s;
    map<char, int> mp;
    for(int i = 0; i < (int) s.size(); i++){
        mp[s[i]]++;
    }

    debug(s);
    int res = fact[s.size()];
    for(auto u : mp){
        res  = (res*inv[u.second])%MOD;
    }

    debug(res);
    //cout << res << endl;
    //cout << s.size() << endl;
    cout << res << endl;
}