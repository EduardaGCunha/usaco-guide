#include <bits/stdc++.h>
using namespace std;

int main(){
    int t; cin >> t;
    while(t--){
        long long a, b, c, d;
        cin >> a >> b >> c >> d;
        long long f = a*d;
        long long g = b*c; 
        if(f == g){
            cout << 0 << endl;
            continue;
        }
        if(g != 0 && f % g == 0 || f != 0 && g % f == 0) cout << 1 << endl;
        else cout << 2 << endl;
    }
}