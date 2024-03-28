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
        auto k = upper_bound(arr, arr+n, x)-arr;
        cout << k << endl;
    }
}