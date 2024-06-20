#include <bits/stdc++.h>
using namespace std;

int main(){
    freopen("maxcross.in", "r", stdin);
    freopen("maxcross.out", "w", stdout);
    int n, k, b; cin >> n >> k >> b;
    vector<int> val(n+1, 0);
    int prefix[n+2];
    prefix[0] = 0;
    for(int i = 0; i < b; i++){
        int a; cin >> a;
        val[a]=1;
    }

    prefix[0] = 0;
    for(int i = 1; i <= n+1; i++){
        prefix[i] = prefix[i-1] + val[i-1];
    }

    int ans = 1e9;
    for(int i = 1; i <= n - k + 1; i++){
        ans = min(ans, prefix[i+k] - prefix[i]);
    }
    cout << ans << endl;
} 