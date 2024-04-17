#include <bits/stdc++.h>
using namespace std;

int main(){
    freopen("whereami.in", "r", stdin);
    freopen("whereami.out", "w", stdout);
    int n; cin >> n;
    string s; cin >> s;
    set<string> patterns;
    int i;
    for(i = 1; i <= n; i++){
        bool dups = false;
        for(int j = 0; j <= n - i; j++){
            string p = s.substr(j, i);
            if(patterns.count(p)){
                dups = true;
                break;
            }
            else patterns.insert(p);
        }
        if(!dups) break;
    }

    cout << i << endl;
}