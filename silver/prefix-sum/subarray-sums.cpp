#include <bits/stdc++.h>
using namespace std;
 
#define ll long long
int main(){
    int n, k; cin >> n >> k;
    map<ll,int> prefix;
    ll ans = 0, sum = 0;
    prefix[0] = 1;
    for(int i = 0; i < n; i++){
        int a; cin >> a;
        sum += a;
        ans += prefix[sum - k];
        prefix[sum]++;
    }
    cout << ans << '\n';
}
