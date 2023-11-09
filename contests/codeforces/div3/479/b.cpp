#include <bits/stdc++.h>
using namespace std;

int n;
string s;

void solve(){
    int m = 0;
    string ans;
    for(int i = 0; i < n - 1; i++){
        int cnt = 0;
        for(int j = 0; j < n - 1; j++){
                if(s[i] == s[j] && s[i+1] == s[j+1]){
                    cnt++;
                }
        }
        if(cnt > m){
                m = cnt;
                ans = string(1, s[i]) + string(1, s[i+1]);
        }
    }
    cout << ans << endl;                                                                                                    
}

int main(){
    cin >> n;  cin >> s;
    solve();
}