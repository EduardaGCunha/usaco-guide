#include <bits/stdc++.h>
using namespace std;

#define int long long

signed main(){
    int n; cin >> n; 
    vector<int> prefix(n+1);
    prefix[0]=0;
    for(int i = 1; i <= n; i++){
        int a; cin >> a;
        prefix[i] = prefix[i-1] + a;
    }
    int maxsum = prefix[1], minsum = prefix[0];
    for(int i = 1; i <= n; i++){
        maxsum = max(prefix[i] - minsum, maxsum);
        minsum = min(prefix[i], minsum);
    }
    cout << maxsum << endl;
}