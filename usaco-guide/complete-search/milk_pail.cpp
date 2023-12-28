#include <bits/stdc++.h>
using namespace std;

int main(){
    freopen("pails.in", "r", stdin);
    freopen("pails.out", "w", stdout);
    int x, y, m; 
    cin >> x >> y >> m;
    int xd = m/x, yd = m/y;
    int mx = 0;
    for(int i = 0; i <= xd; ++i){
        for(int j = 0; j <= yd; j++){
            if((x*i + y*j) <= m){
                mx = max(mx, (x*i + y*j));
            }
        }
    }

    cout << mx << endl;
}
