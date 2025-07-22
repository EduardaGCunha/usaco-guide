#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(0); cin.tie(0)
#define int long long
#define endl '\n'

void solve(){
	int n, k; cin >> n >> k;
    int arr[n];
    for(int i = 0; i < n; i++) cin >> arr[i];
    sort(arr, arr+n);
    int idx = 0;
    while(arr[idx] == 1) idx++;
    int ans = idx*(idx-1)/2;
    map<vector<int>, int> mp;
    vector<int> vazio;
    for(int i = idx; i < n; i++){
        vector<int> inv, fact;
        int x = arr[i], pos = 1;
        //cout << "divisores do: " << arr[i] << endl;
        for(int j = 2; j*j <= x; j++){
            int cnt = 0;
            while(!(x%j)){
                x /=j;
                cnt++;
            }
            cnt %= k;
            if(cnt == 0) continue;
            if(cnt < k){
                pos = 0;
                fact.push_back(j);
                fact.push_back(cnt);
                inv.push_back(j);
                inv.push_back(k-cnt);
            }
            //cout << j << " " << cnt << endl;
        }
        if(x > 1){
            pos = 0;
            inv.push_back(x);
            inv.push_back(k-1);
            fact.push_back(x);
            fact.push_back(1);
            //cout << x << " " << 1 << endl;
        }
        if(pos){
            ans += idx; 
            ans += mp[vazio];
            mp[vazio]++;
        }else{
            ans += mp[inv];
            mp[fact]++;
        }
    }
    cout << ans << endl;
}

signed main(){
	fastio;
	int t; //cin >> t;
    t = 1;
	while(t--){
		solve();
	}
}