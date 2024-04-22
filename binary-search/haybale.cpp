#include <bits/stdc++.h>
using namespace std;

#define int long long

signed main(){
    freopen("haybales.in", "r", stdin);
    freopen("haybales.out", "w", stdout);
    int n, q; cin >> n >> q;
    int arr[n+1];
    for(int i = 0; i < n; i++) cin >> arr[i];
    sort(arr, arr+n);
    for(int i = 0; i < q; i++){
        int a, b; cin >> a >> b;
        auto k = lower_bound(arr, arr+n, a)-arr;
        auto j = upper_bound(arr, arr+n, b) - arr;
        cout << j - k << endl;
    }
}