#include <bits/stdc++.h>
using namespace std;

#define int long long

signed main(){
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        vector<int> arr(n+1);
        int sum = 0;
        for(int i = 0;i < n; i++){
            cin >> arr[i];
            sum += arr[i];
        }
        int ans = 2;
        if(sum%3 != 0){
            if(sum%3 == 2) ans = 1;
            else{
                for(int i = 0; i < n; i++){
                    if((sum - arr[i])%3 == 0) ans = 1;
                }
            }
        }else ans = 0;
        cout << ans << endl;
        
    }
}