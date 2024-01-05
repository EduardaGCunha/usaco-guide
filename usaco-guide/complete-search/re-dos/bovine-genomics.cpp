#include <bits/stdc++.h>
using namespace std;

int main(){
    freopen("cownomics.in", "r", stdin);
    freopen("cownomics.out", "w", stdout);
    int n, m; cin >> n >> m;
    vector<string> plain(n), spotty(n);
    for(int i = 0; i < n; i++) cin >> plain[i];
    for(int i = 0; i < n; i++) cin >> spotty[i];

    int cnt = 0;
    for(int i =0; i < m; i++){
        set<char> plain_g, spotty_g;
        for(int j = 0; j < n; j++){
            plain_g.insert(plain[j][i]);
            spotty_g.insert(spotty[j][i]);
        }
        bool passed = false;
        for(char a : plain_g){
            for(char b : spotty_g){
                if(a == b) passed = true;
            }
        }
        if(!passed) cnt++;
    }

    cout << cnt << endl;
}