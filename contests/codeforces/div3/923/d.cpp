#include <bits/stdc++.h>
using namespace std;

int main(){
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        int a[n], b[n];
        for(int i = 1; i <= n; i++) cin >> a[i];
        b[n] = n+1;
        for(int i = n - 1; i >= 1; i--){
            if(a[i] != a[i+1]) b[i] = i + 1;
            else b[i] = b[i + 1];
        }
        int q; cin >> q;
        while(q--){
            int l, r; cin >> l >> r;
            if(b[l] <= r) cout << l << " " << b[l] << endl;
            else cout << -1 << " " << -1 << endl;
        }
    }
}