#include <bits/stdc++.h>
using namespace std;

#define int long long

signed main(){
    int n, m; cin >> n >> m;
    int arr[n];
    for(int i = 0; i < n; i++) cin >> arr[i];

    vector<int> pfx(n+2, 0);
    for(int i = 0; i < m; i++){
        int a, b; cin >> a >> b;
        pfx[a]++;
        pfx[b+1]--;
    }

    for(int i = 1; i <= n+1; i++){
        pfx[i] += pfx[i-1];
       // cout << pfx[i] << " ";
    }
   // cout << endl;

    sort(arr, arr+n);
    sort(pfx.begin(), pfx.end());
    int ans = 0;
    for(int i = 2; i <= n+1; i++){
        //cout << pfx[i] << " " << arr[i-2] << endl;
        ans += pfx[i]*arr[i-2];
    }
    cout << ans << endl;
}