#include <bits/stdc++.h>
using namespace std;

#define int long long 
#define endl "\n"
#define fastio ios_base::sync_with_stdio(0); cin.tie(0)

signed main(){
    fastio;
    int n; cin >> n;
    int arr[n];
    for(int i = 0; i < n; i++) cin >> arr[i];

    map<int, int> dp; 

    int ans = 0; 
    int lst = 0;
    for(int i = 0; i < n; i++){
        dp[arr[i]] = dp[arr[i]-1] + 1;
        if(ans < dp[arr[i]]){
            ans = dp[arr[i]];
            lst = arr[i]; 
        }
       
    }

    vector<int> res;
    for(int i = n-1; i>=0; i--){
        if(arr[i] == lst){
            res.push_back(i);
            lst--;
        }
    }

    cout << ans << endl;
    reverse(res.begin(), res.end());
    for(auto u : res){
        cout << u+1 << " ";
    }
    cout << endl;
}
