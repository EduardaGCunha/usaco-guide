#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl "\n"
#define fastio ios_base::sync_with_stdio(0); cin.tie(0)


signed main(){
    fastio;
    int n; cin >> n;
    vector<int> arr(n);
    for(int i = 0; i < n; i++) cin >> arr[i];

    vector<int> dp;
    for(int i = 0; i < n; i++){
        int pos = lower_bound(dp.begin(), dp.end(), arr[i]) - dp.begin();
        if(pos == (int) dp.size()){
            dp.push_back(arr[i]);
        }else{
            dp[pos] = arr[i];
        }
    }

    cout << dp.size() << endl;
}