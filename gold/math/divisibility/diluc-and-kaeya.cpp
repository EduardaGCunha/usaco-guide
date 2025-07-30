#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(0); cin.tie(0)
#define int long long
#define endl '\n'

void solve(){
	int n; cin >> n;
    string s; cin >> s;
    int d = 0, k = 0;
    map<pair<int, int>, int> mp;
    for(int i = 0; i < n; i++){
        if(s[i] == 'D') d++;
        else k++;
        int x = gcd(d, k);
        pair<int, int> p = {(d/x), (k/x)};
        mp[p]++;
        cout << mp[p] << " "; 
    }
    cout << endl;
}

signed main(){
	fastio;
	int t; cin >> t;
	while(t--){
		solve();
	}
}