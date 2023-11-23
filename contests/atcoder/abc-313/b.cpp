#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main(){
    ll n, m; cin >> n >> m;
    vector<int> values(n+1, 0);
    for(int i = 1; i <= m; i++){
        ll a, b; cin >> a >> b; 
        values[b]++;
    }

    int cnt = 0, ans = 0;
    for(int i = 1; i <= n; i++){
        if(values[i] == 0) cnt++, ans = i;
    }
    
    if(cnt == 1) cout << ans << endl;
    else cout << -1 << endl;

}