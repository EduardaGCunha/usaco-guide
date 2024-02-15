#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(0); cin.tie(0)
#define int long long

signed main(){
    fastio;
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        int arr[n+1], prefix[n+1], sufix[n+1];
        for(int i = 0; i < n; i++) cin >> arr[i];
        prefix[0] = sufix[n] = 0;
        for(int i = 0; i < n; i++){
            prefix[i] = arr[i] + i;
            sufix[i] = arr[i] - i;
        }

        for(int i = 1; i < n; i++) prefix[i] = max(prefix[i], prefix[i-1]);
        for(int i = n-2; i >= 0; i--) sufix[i] = max(sufix[i], sufix[i+1]);

        int ans = 0;
        for(int i = 1; i < n-1; i++){
            ans = max(ans, prefix[i-1] + arr[i] + sufix[i+1]);
        }
        
        cout << ans << endl;
    }
}  