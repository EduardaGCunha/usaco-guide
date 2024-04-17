#include <bits/stdc++.h>
using namespace std;

#define int long long
#define fastio ios_base::sync_with_stdio(0); cin.tie(0)

signed main(){
    fastio;
    int n; cin >> n;
    int arr[n+1];
    for(int i = 0; i < n; i++) cin >> arr[i];
    sort(arr, arr+n);
    int mid = arr[n/2];
    int ans = 0;
    for(int i = 0; i < n; i++){
        ans += abs(arr[i] - mid);
    }
    cout << ans << endl;
}