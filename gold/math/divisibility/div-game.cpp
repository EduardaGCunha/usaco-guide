#include <bits/stdc++.h>
using namespace std;

#define int long long

signed main(){
    int n; cin >> n;
    int ans =0;
    for(int i = 2; i*i <= n; i++){
        int cnt = 0;
        while(!(n%i)){
            cnt++;
            n/=i;
        }

        //cout << i << " " << cnt << endl;
        for(int j = 1; cnt - j >= 0; j++){
            ans++;
            cnt -= j;
        }
    }

    if(n>1) ans++;

    cout << ans << endl;
}