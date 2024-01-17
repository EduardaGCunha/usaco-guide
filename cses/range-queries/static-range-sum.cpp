#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main(){
    int n, m; cin >> n >> m;
    ll prefix[n+1];
    prefix[0] = 1;
    for(int i = 1; i <= n; i++){
        ll a; cin >> a;
        prefix[i] = a + prefix[i-1];
    }
    while(m--){
        int a, b; cin >> a >> b;
        cout << prefix[b] - prefix[a-1] << endl;
    }
}