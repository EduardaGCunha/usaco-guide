#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(0); cin.tie(0)
#define int long long
#define endl '\n'

const int MOD = 998244353;

int fastexpo(int a, int b){
    int res = 1;
    while(b > 0){
        if(b&1) res = (res*a) % MOD;
        a = (a*a)%MOD;
        b/=2;
    }   
    return res;
}

signed main(){
	fastio;
	int n, k = 0; cin >> n;
    map<int, int> mp;
    vector<vector<int>> v(n);
    for(int i = 0; i < n; i++){
        int m; cin >> m;
        v[i].resize(m);
        k += m;
        for(int j = 0; j < m; j++){
            int x; cin >> x;
            v[i][j] = x;
            mp[x]++;
        }
    }

    //what is the total amount of triples we can make?
    int invn = fastexpo(n, MOD-2);
    int ans = 0;
    for(int i = 0; i < n; i++){
        int inv = fastexpo(v[i].size(), MOD-2);
        for(auto u : v[i]){
            ans = (ans + (mp[u]*1LL*inv)%MOD)%MOD;
        }
    }
    ans = ((ans*1LL*invn)%MOD * invn % MOD);
    cout << ans << endl;
}