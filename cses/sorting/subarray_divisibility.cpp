#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main(){
    int n; cin >> n;
    vector<ll> val(n, -1);
    val[0] = 0;
    ll ans = 0, sum = 0;
    for(int i = 0; i < n; i++){
        int a; cin >> a;
        sum = ((sum+a)%n + n)%n;
        ans = ++val[sum];
    }
    cout << ans << endl;
}