#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, m; cin >> n >> m;
    vector<int> a(n), b(m);
    for(int i = 0; i < n; i++) cin >> a[i];
    for(int i = 0; i < m; i++) cin >> b[i];
    int res = 0;
    for(int i = 0; i < n; i++){
        auto it = lower_bound(b.begin(), b.end(), a[i]);
        int ans = INT_MAX;
        if(it != b.begin()){
            ans = min(ans, abs(a[i] - (*prev(it))));
        }
        if(it != b.end()){
            ans = min(ans, abs(a[i] - (*it)));
        }
        res = max(ans, res);
    }
    
    cout << res << endl;
}