#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(0); cin.tie(0)
#define int long long

signed main(){
    int n, m; cin >> n >> m;
    int arr[n+1];
    for(int i = 0; i < n; i++) cin >> arr[i];
    // for(int i = 0; i < m; i++){
    //     int a; cin >> a;
    //     auto k = lower_bound(arr, arr+n, a)-arr;
    //     if(k < n && arr[k] == a) cout << "YES" << endl;
    //     else cout << "NO" << endl;
    // }
    for(int i = 0; i < m; i++){
        int x; cin >> x;
        int k = 0;
        for(int j = n/2; j >= 1; j/=2){
            while(k+j < n && arr[k+j] <= x) k += j;
        }
        if(arr[k] == x) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
}