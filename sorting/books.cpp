#include <bits/stdc++.h>
using namespace std;

#define int long long

signed main(){
    int n, m; cin >> n >> m;
    int arr[n+1];
    for(int i = 0; i < n; i++) cin >> arr[i];
    int ans = 0;
    for(int i = 0, j = 0, sum = 0; i < n; i++){
        sum += arr[i];
        while(sum > m){
            sum -= arr[j];
            j++;
        }
        if(sum <= m){
            ans = max(ans, i - j + 1);
        }
    }

    cout << ans << endl;
}