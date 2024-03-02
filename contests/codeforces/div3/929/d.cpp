#include <bits/stdc++.h>
using namespace std;

#define int long long
const int MOD = 10000007;

int fastexpo(int a, int b){
    int res = 1;
    while(b > 0){
        if(b%2) res = (res*a)%MOD;
        a = (a*a)%MOD;
        b /= 2;
    }
    return res;
}

signed main(){
    int t; cin >> t;
    while(t--){
        int a, b,c, d, k; cin >> a >> b >> k;
        int ans = 0;
        if(a == b){
            for(int i = 0; i < 100; i++){
                c = fastexpo(a, i);
                if(k%c==0) ans++;
            }
            continue;
        }
        for(int i = 0; i < 100; i++){
            c = fastexpo(a, i);
            if(c > k) continue;
            for(int j = 0; j < 100; j++){
                d = fastexpo(b, j);
                if(d > k) continue;
                if(c*d > k) continue;
                if(k%(c*d)==0) ans++;
            }
        }
    }
}