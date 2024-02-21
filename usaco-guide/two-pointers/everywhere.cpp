#include <bits/stdc++.h>
using namespace std;

#define int long long

signed main(){
    int n; cin >> n;
    string s; cin >> s;
    map<char, int> m;
    for(int i = 0; i < n; i++) m[s[i]]++;
    int v=m.size();
    m.clear();
    int j = 0, ans = n;
    for(int i = 0; i < n; i++){
        while(j < n && m.size() < v) m[s[j++]]++;
        if(m.size() == v) ans = min(ans, j - i);
        if(!--m[s[i]]) m.erase(s[i]);
    }
 
    cout << ans << '\n';

}