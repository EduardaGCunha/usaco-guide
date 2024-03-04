#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(0); cin.tie(0)
#define int long long

signed main(){
    int n, m, k; cin >> n >> m >> k;
    vector<int> apartments(n+1);
    for(int i = 0; i < n; i++) cin >> apartments[i];
    sort(apartments.begin(), apartments.end());
    int ans = 0;
    for(int i = 0; i < m; i++){
        int a; cin >> a;
        auto it1 = lower_bound(apartments.begin(), apartments.end(), a+k);
        auto it2 = lower_bound(apartments.begin(), apartments.end(), a-k);
        auto it3 = lower_bound(apartments.begin(), apartments.end(), a);
        if(it1 != apartments.end() || it2 != apartments.end()){
            if(*it1 == a+k || *it2 == a-k) ans++;
        }
    }
    cout << ans << endl;
}