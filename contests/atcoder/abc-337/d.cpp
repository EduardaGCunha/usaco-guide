#include <bits/stdc++.h>
using namespace std;

#define int long long

signed main(){
    int w, h, k; cin >> h >> w >> k;
    vector<string> s(h);
    for(int i = 0; i < h; i++){
        cin >> s[i];
    }
    int ans = 1e9;
    for(int i = 0; i < h; i++){
        int cnt = 0, sz = 0;
        for(int j = 0; j < w; j++){
            if(s[i][j] == 'x'){
                cnt = sz = 0;
                continue;
            }
            if(s[i][j] == '.') cnt++;
            sz++;
            if(sz > k){
                sz--;
                cnt -= (s[i][j-k] == '.');
            }
            if(sz == k) ans = min(ans, cnt);
        }
    }

    for(int j = 0; j < w; j++){
        int cnt = 0, sz = 0;
        for(int i = 0; i < h; i++){
            if(s[i][j] == 'x'){
                cnt = sz = 0;
                continue;
            }
            if(s[i][j] == '.') cnt++;
            sz++;
            if(sz > k){
                sz--;
                cnt -= (s[i-k][j] == '.');
            }
            if(sz == k) ans = min(ans, cnt);
        }
    }
    if(ans == 1e9) ans = -1;
    cout << ans << endl;
    
}