#include <bits/stdc++.h>
using namespace std;

int main(){
    freopen("cownomics.in", "r", stdin);
    freopen("cownomics.out", "w", stdout);
    int n, m; cin >> n >> m;
    vector<string> plain(n), spotty(n);
    for(int i = 0; i < n; i++) cin >> plain[i];
    for(int j = 0; j < n; j++) cin >> spotty[j];
    

    int cnt = 0;
    for(int i = 0; i < m; i++){
        for(int j = i + 1; j < m; j++){
            for(int k = j + 1; k < m; k++){
                set<string> spotty_g;
                string s(3, '0');
                for(int l = 0; l < n; l++){
                    s[0] = spotty[l][i]; s[1] = spotty[l][j]; s[2] = spotty[l][k];
                    spotty_g.insert(s);
                }

                bool passed = true;
                for(int l = 0; l < n; l++){
                    s[0] = plain[l][i]; s[1] = plain[l][j]; s[2] = plain[l][k];
                    if(spotty_g.count(s)){
                        passed = false;
                        break;
                    }
                }

                if(passed) cnt++;  
            }
        }
    }

    cout << cnt << endl;
}