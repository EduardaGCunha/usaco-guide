#include <bits/stdc++.h>
using namespace std;
 
#define fastio ios_base::sync_with_stdio(0); cin.tie(0)
#define int long long
 
signed main(){
    fastio;
    int n, m; cin >> n >> m;
    multiset<int> mp;
    for(int i = 0; i < n; i++){
        int a; cin >> a;
        mp.insert(a);
    }
 
    for(int i = 0; i < m; i++){
        int b; cin >> b;
        auto it = mp.upper_bound(b);
        if(it != mp.begin()){
            --it;
            cout << *(it) << endl;
            mp.erase(mp.find(*it));
        }else cout << -1 << endl;
    }
}