#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main(){
    int n; cin >> n;   
    ll sum = 0, ans = 0;
    vector<ll> m(n);
    m[0] = 1;
    for(int i = 0; i < n; i++){
        ll a; cin >> a;
        sum += a;
        m[(sum%n + n)%n]++;
    }

    for(ll a : m){
        ans += ((a)*(a-1))/2;
    }

    cout << ans << endl;
}