#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(0); cin.tie(0)
#define int long long
#define endl '\n'

void solve(){
    int n, k; cin >> n >> k;
    vector<pair<int, int>> v;
    for(int i = 0; i < n; i++){
        int x; cin >> x;
        v.push_back({x, i});
    }

    sort(v.begin(), v.end());
    int mx = -1, a = 0, b = 0, x = 0;
    for(int i = 1; i < n; i++){
        int x2 = v[i].first^((1<<k)-1);
        int val = (v[i].first^x2) & (v[i-1].first^x2);
        if(mx < val){
            mx = val;
            x = x2;
            a = v[i].second+1;
            b = v[i-1].second+1;
        }
    } 
    if(a > b) swap(a, b);
    cout << a << " " << b << " " << x << endl;
}

signed main(){
	fastio;
	int t; cin >> t;
	while(t--){
		solve();
	}
}