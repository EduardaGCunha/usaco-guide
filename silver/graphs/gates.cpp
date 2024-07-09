#include <bits/stdc++.h>
using namespace std;

int main(){
    freopen("gates.in", "r", stdin);
    freopen("gates.out", "w", stdout);
    int n; cin >> n;
    string s; cin >> s;
    int ans = 0;
    int x = 0, y = 0, a = 0, b = 0;
    set<pair<int, int>> p;
    p.insert({a, b});
    for(int i = 0; i < n; i++){
        if(s[i] == 'N') x++;
        else if(s[i] == 'S') x--;
        else if(s[i] == 'E') y--;
        else y++;


        if(p.find({x, y}) != p.end()){
            ans++;
        }
        p.insert({x, y});
    }

    //cout << ans << endl;
}