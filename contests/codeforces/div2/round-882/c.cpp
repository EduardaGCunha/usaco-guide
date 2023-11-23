#include <bits/stdc++.h>
using namespace std;

#define int long long
 
signed main(){
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        int values[n];
        
        int pre[n+1] = {};
        for(int i = 0; i < n; i++) cin >> values[i];
 
        for(int i = 0; i < n; i++){
            pre[i+1]=(pre[i]^values[i]);
        }

        int m = 0;
        for(int i = 0; i < n; i++){
            for(int j = i; j <= n; j++){
                m = max(m, pre[j]^pre[i]);
            }
        }
 
        cout << m << endl;
    }
}