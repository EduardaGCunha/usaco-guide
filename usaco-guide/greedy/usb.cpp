#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(0); cin.tie(0)
#define int long long

signed main(){
    int u, p, b; cin >> u >> p >> b;
    int n; cin >> n;
    vector<pair<int, string>> v(n);
    for(int i = 0; i < n; i++){
        cin >> v[i].first >> v[i].second;
    }
    sort(v.begin(), v.end());
    int comp = 0, price = 0;
    for(int i = 0; i < n; i++){
        if(u && v[i].second == "USB") u--;
        else if(p && v[i].second == "PS/2") p--;
        else if(b) b--;
        else continue;
        comp++;
        price += v[i].first;
    }
    cout << comp << " " << price << endl;
}