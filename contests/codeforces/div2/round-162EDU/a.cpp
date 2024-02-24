#include <bits/stdc++.h>
using namespace std;

#define int long long

signed main(){
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        int arr[n+1];
        vector<int> val;
        for(int i = 1; i <= n; i++){
            int a; cin >> a;
            arr[i] = a;
            if(a == 0) continue;
            val.push_back(i);
        }

        int ans = 0;
        int l = val.front(), r = val.back();
        while(l < r){
            if(arr[l] == 0) ans++;
            l++;
        }
        cout << ans << endl;
    }
}