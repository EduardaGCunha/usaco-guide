#include <bits/stdc++.h>
using namespace std;

#define int long long

signed main(){
    int n, q; cin >> n >> q;
    int prefix[n+1];
    prefix[0] = 0;
    for(int i = 1; i <= n; i++){
        int x; cin >> x;
        prefix[i] = (prefix[i-1]^x);
    }

    while(q--){
        int a, b; cin >> a >> b;
        cout << (prefix[b]^prefix[a-1]) << endl;
    }
}