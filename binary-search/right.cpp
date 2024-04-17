#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(0); cin.tie(0)
#define int long long

signed main(){
    fastio;
    int n, m; cin >> n >> m;
    int arr[n+1];
    for(int i = 0; i < n; i++) cin >> arr[i];
    for(int i = 0; i < m; i++){
        int x; cin >> x;
        auto k = lower_bound(arr, arr+n, x);
        if(k == arr+n) cout << n+1 << endl;
        else cout << k-arr+1 << endl;
    }
}