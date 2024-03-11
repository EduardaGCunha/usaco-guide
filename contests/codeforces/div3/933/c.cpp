#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(0); cin.tie(0)

int main(){
    fastio;
    int t; cin >> t;
    while(t--){
       int n; cin >> n;
       string s; cin >> s;
       int ans = 0;
       for(int i = 0; i < n-2; i++){
            if(s.substr(i, 3) == "map" || s.substr(i, 3) == "pie"){
                ans++;
                i+= 2;
            }
       }
       cout << ans << endl;
    }
}