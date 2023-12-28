#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main(){
    int n; cin >> n;
    vector<ll> x(n);
    vector<ll> y(n);
    for(int i = 0; i < n; i++) cin >> x[i];
    for(int i = 0; i < n; i++) cin >> y[i];

    ll mx = 0;
    for(int i = 0; i < n - 1; i++){
        for(int j = i + 1; j < n; j++){
           ll dx = x[i] - x[j];
           ll dy = y[i] - y[j];
           mx = max(mx, dx*dx + dy* dy);
        }
    }

    cout << mx << endl;
}