#include <bits/stdc++.h>
using namespace std;

#define int long long

signed main(){
    int n; cin >> n;
    vector<int> pfx(n+1);
    pfx[0] = 0;
    for(int i = 1; i <= n; i++){
        int x; cin >> x;
        pfx[i] = pfx[i-1] + x;
    }

    int ans = pfx[1], low = pfx[0];
    for(int i = 1; i <= n; i++){
        //cout << pfx[i] - low << " " << low << " " << pfx[i] << endl;
        ans = max(ans, pfx[i] - low);
        low = min(low, pfx[i]);
    }

    cout << ans << endl;
}