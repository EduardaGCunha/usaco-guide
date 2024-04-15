#include <bits/stdc++.h>
using namespace std;

//#define fastio ios_base::sync_with_stdio(0); cin.tie(0)
//#define int long long

int main(){
    int n; cin >> n;
    int i = 8, cnt = 0;
    while(n > 0){
        if(i <= n){
            n -= i;
            cnt++;
        }
        i /= 2;
    }
    cout << cnt << endl;
}