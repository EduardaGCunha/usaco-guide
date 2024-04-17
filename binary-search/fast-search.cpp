#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(0); cin.tie(0)
#define int long long

signed main(){
    int n; cin >> n;
    int arr[n+1];
    for(int i = 0; i < n; i++) cin >> arr[i];
    sort(arr, arr+n);
    int k; cin >> k;
    while(k--){
        int a, b; cin >> a >> b;
        auto c = lower_bound(arr, arr+n, a)-arr;
        auto d = upper_bound(arr, arr+n, b)-arr;
        cout << (d-c) << " ";
    }
    cout << endl;
}