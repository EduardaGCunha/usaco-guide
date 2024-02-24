#include <bits/stdc++.h>
using namespace std;

int main(){
    int t; cin >> t;
    while(t--){
        int n; cin >>n;
        string s; cin >> s;
        int l = 0, ans = 0;
        while(l < n){
            if(s[l] == '@') ans++;
            if(s[l] == '*' && s[l+1] == '*') break;
            l++;
        }
        cout << ans << endl;
    }
}