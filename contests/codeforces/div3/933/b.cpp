#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(0); cin.tie(0)
#define int long long

signed main(){
    fastio;
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        int arr[n+1];
        string res = "YES";
        for(int i = 0; i < n; i++) cin >> arr[i];
        for(int i = 0; i < n-2; i++){
            if(arr[i] == 0) continue;
            if(arr[i] < 0){
                res = "NO";
                break;
            }else{
                arr[i+1] -= 2*arr[i];
                arr[i+2] -= arr[i];
            }
        }
        if(arr[n-1] != 0 || arr[n-2] != 0) res = "NO";
        cout << res << endl;
    }
}