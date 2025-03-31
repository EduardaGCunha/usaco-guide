#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(0); cin.tie(0)
#define int long long

signed main(){
    fastio;
    int n; cin >> n;
    vector<int> t(n, 0);
    int mm = 1, cnt = 0;
    for(int i = 1; i < n; i++){
        if(gcd(i, n) == 1){
            mm = (mm*i)%n;
            t[i] = 1;
            cnt++;
        }
    }

    if(mm != 1){
        t[mm] = 0;
        cnt--;
    }
    cout << cnt << endl;

    for(int i = 1; i < n; i++){
        if(t[i]) cout << i << " ";
    }
    cout << endl;
}