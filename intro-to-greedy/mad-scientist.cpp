#include <bits/stdc++.h>
using namespace std;

int main(){
    freopen("breedflip.in", "r", stdin);
    freopen("breedflip.out", "w", stdout);
    int n; cin >> n;
    string s, t; cin >> s >> t;
    int cnt = 0;
    int i = 0;
    while(i < n){
        if(s[i] == t[i]){
            i++;
            continue;
        }
        cnt++;
        while(s[i] != t[i]){
            i++;
        }
    }
    cout << cnt << endl;
}