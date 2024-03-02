#include <bits/stdc++.h>
using namespace std;

#define int long long

signed main(){
    int t; cin >> t;
    while(t--){
        int n, k; cin >> n >> k;
        int arr1[n+1], arr2[n+1];
        vector<int> v(n+1);
        for(int i = 0; i < n; i++) cin >> arr1[i];
        for(int i = 0; i < n; i++) cin >> arr2[i];
        for(int i = 0; i < n; i++) v[abs(arr2[i])] += arr1[i];
        int left = 0; bool res = true;
        for(int i = 1; i <= n; i++){
            left += k - v[i];
            res &= (left >= 0);
        }
        if(res)cout << "YES" << endl;
        else cout <<"NO" << endl;
    }
}