#include <bits/stdc++.h>
using namespace std;

#define int long long

signed main(){
    freopen("diamond.in", "r", stdin);
    freopen("diamond.out", "w", stdout);
    int n, k; cin >> n >> k;
    vector<int> d(n);
    for(int i = 0; i < n; i++) cin >> d[i];
    sort(d.begin(), d.end());

    int l = 0, r = 0;
    vector<int> belowI(n+1), aboveI(n+1);
    while(r < n){
        while(l > r)   r++;
        if(d[r] - d[l] <= k){
            belowI[r] = max(belowI[r], r - l+1);
            aboveI[l] = max(aboveI[l], r - l+1);
            r++;
        }else l++;
    } 

    while(l < n)
    {
        aboveI[l] = max(aboveI[l], r - l);
        l++;
    }  

    int ans = 0, mx=0;
    for(int i = 1; i < n; i++){
        mx = max(mx, belowI[i-1]);
        ans = max(ans, mx + aboveI[i]);
    }

    cout << ans << endl;
}