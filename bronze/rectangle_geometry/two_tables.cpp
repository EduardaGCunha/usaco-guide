#include <bits/stdc++.h>
using namespace std;

int main(){
    int t; cin >> t;
    while(t--){
        int n, m; cin >> n >> m;
        int x1, x2, y1, y2; cin >> x1 >> y1 >> x2 >> y2;
        int w, h; cin >> w >> h;
        if(x2 + (w-x1) > n && y2 + (h-y1) > m){
            cout << -1 << endl;
            continue;
        }
        cout << min(x2 - abs(w-x1), y2 - abs(h-y1)) << endl;
    }
}