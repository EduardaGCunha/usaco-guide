#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main(){
    int t; cin >> t;
    while(t--){
        ll n; cin >> n;
        map<char, ll> alpha;
        string s; cin >> s;
        ll mx = 0;
        for(int i = 0; i < n; i++){
            alpha[s[i]]++;
            mx = max(mx, alpha[s[i]]);
        }
        if(mx > n/2) cout << n - (n-mx)*2 << endl;
        else cout << n%2 << endl;
        
    }
}