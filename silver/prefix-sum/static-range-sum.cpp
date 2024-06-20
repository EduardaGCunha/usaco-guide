#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main(){
    ll n, q; cin >> n >> q;
    vector<ll> arr(n+1, 0);
    for(ll i = 1; i <= n; i++){
        ll a; cin >> a;
        arr[i] = arr[i-1] + a;
    }

    while(q--){
        ll a, b; cin >> a >> b;
        cout << arr[b] - arr[a] << endl;
    }
}