#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(0); cin.tie(0)
#define int long long
#define endl '\n'

void solve(){
	int n; cin >> n;
    int arr[n];
    //qual eh o tamanho maximo do gcd se eu terminar em i?
    vector<map<int, int>> maxsize(n);
    for(int i = 0; i < n; i++){
        cin >> arr[i];
        maxsize[i][arr[i]] = 1; //tamanho maximo com o valor original eh 1
    }

    for(int i = 1; i < n; i++){
        for(auto [gcd, size] : maxsize[i-1]){
            int val = __gcd(gcd, arr[i]);
            maxsize[i][val] = max(maxsize[i][val], size+1);
        }
    }

    vector<int> ans(n+1);
    for(int i = 0; i < n; i++){
        for(auto [gcd, size] : maxsize[i]){
            ans[size] = max(ans[size], gcd);
        }
    }

    for(int i = 1; i <= n; i++){
        cout << ans[i] << " ";
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