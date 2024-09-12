#include <bits/stdc++.h>
using namespace std;

int main(){
    int n; cin >> n;
    map<string, string> mp;
    while(n--){
        string s, t; cin >> s >> t;
        mp[s] = t;
    }

    cout << "comeca aq\n";
    for(const auto &u : mp){
        cout << u.first << " " << u.second << endl;
    }
}