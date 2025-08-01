#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(0); cin.tie(0)
#define int long long
#define endl '\n'

const int MOD = 1e9+7;

int fastexpo(int a, int b){
    int res = 1;
    a%=MOD;
    while(b >= 1){
        if(b&1) res = (res*a)%MOD;
        a = (a*a)%MOD;
        b >>= 1;
    }
    return res;
}


signed main(){
	fastio;
	int n; cin >> n;
    vector<pair<int, int>> v;
    int qtd = 1;
    for(int i = 0; i < n; i++){
        int a, b; cin >> a >> b;
        v.push_back({a, b});
        qtd = (qtd*(b+1))%MOD;
    }

    int sum = 1;
    for(int i = 0; i < n; i++){
        //(div^(b*(p+1))-1)/(div - 1)
        int div = v[i].first;
        int f = v[i].second;
        if(div%MOD == 1){
            int prod = ((n%MOD));
        }else{
            int exp = ((f%(MOD-1)) * (n%(MOD-1)))%(MOD-1);
            exp = (exp+1)%(MOD-1);
            int num = (fastexpo(div, exp)-1 + MOD)%MOD;
            int den = (div-1 + MOD)%MOD;
            int prod = (num*(fastexpo(den, MOD-2)))%MOD;
            sum = (sum*prod)%MOD;
        }
    }
    cout << qtd%MOD << " " << sum%MOD << endl;
}