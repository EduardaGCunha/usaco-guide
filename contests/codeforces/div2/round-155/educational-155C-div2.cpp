#include <bits/stdc++.h>
using namespace std;

const int MOD = 998'244'353;

void upd(int &a, int b) {
    a = (a * 1LL * b) % MOD;
}

int main(){
    int t; cin >> t;
    while(t--){
        string s; cin >> s;
        int cnt = 0;
        for(int i = 0; i < s.size() - 1; i++){
            if(s[i] == s[i+1]){
                cnt++;
                upd(cnt+1, cnt - i);
            }
        }
        

        int fact = 1;
        for(int i = 2; i <= cnt + 1; i++){
            fact = (fact * 1LL * i) % MOD;
        }

        cout << cnt % MOD << " " << fact << endl;
    }
}