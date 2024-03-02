#include <bits/stdc++.h>
using namespace std;


signed main(){
    int t; cin >> t;
    while(t--){
        int k, a, b, c, d; cin >> a >> b >> k;
        set<int> ans;
        for(int i = 1; i <= k; i *= a){
            if(k%i) continue;
            for(int j = 1; j*i <= k; j*=b){
                if(k%(j*i)) continue;
                ans.insert(k/(j*i));
            }
        }
        cout << ans.size() << endl;
    }
}