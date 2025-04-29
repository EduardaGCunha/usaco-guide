#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(0); cin.tie(0)

int main(){
    fastio;
    int n; cin >> n;
    int arr[n+1], brr[n+1], pos[n+1], c[n+1];
    for(int i = 1; i <= n; i++){
        cin >> arr[i];
        pos[arr[i]] = i;
    }
    for(int i = 1; i <= n; i++) cin >> brr[i];

    for(int i = 1; i <= n; i++){
        c[i] = pos[brr[i]];
    }

    vector<int> dp;
    for(int i = 1; i <= n; i++){
        int p = lower_bound(dp.begin(), dp.end(), c[i]) - dp.begin();
        if(p == dp.size()) dp.push_back(c[i]);
        else dp[p] = c[i];
    }
    cout << dp.size() << endl;
}