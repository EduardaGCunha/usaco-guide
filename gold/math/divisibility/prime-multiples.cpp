#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(0); cin.tie(0)
#define int long long
#define endl '\n'

/*
how many are divisible by k?
how many are divisible by k1?
*/

signed main(){
	fastio;
	int n, k; cin >> n >> k;
    vector<int> primes(k);
    for(int i = 0; i < k; i++){
        cin >> primes[i];
    }

    int ans = 0;
    for(int mask = 1; mask < (1<<k); mask++){
        __int128 prod = 1;
        for(int i = 0; i < k; i++){
            if(mask&(1<<i)){
                prod *= primes[i];
                if(prod > n) break;
            }
        }
        if(prod > n) continue;
        int cnt = __builtin_popcount(mask);
        int val = n/prod;
        if(cnt&1) ans += val;
        else ans -= val;
    }
    cout << ans << endl;
    
}
