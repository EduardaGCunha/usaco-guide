#include <bits/stdc++.h>
using namespace std;

#define int long long

signed main(){
    int n; cin >> n;
    int arr[n];
    for(int i = 0; i < n; i++) cin >> arr[i];

    int ans = INT_MAX;
    for(int i = 0; i < (1<<n); i++){
        int sum1 = 0, sum2= 0;
        for(int j = 0; j < n; j++){
            if(i&(1<<j)) sum1 += arr[j];
            else sum2 += arr[j];
        }
        ans = min(abs(sum1-sum2), ans);
    }

    cout << ans << endl;
}