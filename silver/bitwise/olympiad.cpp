#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, l, r, x; cin >> n >> l >> r >> x;

    int arr[n];
    for(int i = 0; i < n; i++) cin >> arr[i];
    sort(arr, arr+n);
    int ans = 0;
    for(int mask = 0; mask < (1<<n); mask++){
        int sum = 0, mini = INT_MAX, maxi = INT_MIN;
        for(int i = 0; i < n; i++){
            if(mask & (1 << i)){
                sum += arr[i];
                mini = min(arr[i], mini);
                maxi = max(arr[i], maxi);
            }
        }
        //cout << sum << " " << maxi << " " << mini << endl;
        if(sum >= l && sum <= r && maxi - mini >= x) ans++;
    }

    cout << ans << endl;
}