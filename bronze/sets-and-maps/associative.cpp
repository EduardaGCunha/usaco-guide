#include <bits/stdc++.h>
using namespace std;

#define int long long

signed main(){
    int t; cin >> t;
    unordered_map<int, int> mp;
    while(t--){
        int x, a; cin >> x >> a;
        if(!x){
            int b; cin >> b;
            mp[a] = b;
        }else cout << mp[a] << endl;
    }
}