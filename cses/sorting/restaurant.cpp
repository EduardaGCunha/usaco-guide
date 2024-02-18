#include <bits/stdc++.h>
using namespace std;

#define int long long

const int MAXN = 200007;

signed main(){
    int n; cin >> n;
    map<int, int> customers;
    for(int i = 0; i < n; i++){
        int a, b; cin >> a >> b;
        customers[a] = 1;
        customers[b] = -1;
    }

    int ans = 0, p = 0;
    for(auto &c : customers){
        p += c.second;
        ans = max(ans, p);
    }

    cout << ans << endl;

}