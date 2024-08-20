#include <bits/stdc++.h>
using namespace std;

int main(){
    freopen("square.in", "r", stdin);
    freopen("square.out", "w", stdout);
    int x, y, x1, y1, x2, y2, x3, y3;
    cin >> x >> y >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;

    int ans = 0;
    ans = max({ans, x1 - x, y1 - y, abs(x2 - x), abs(y2 - y), abs(y3 - y), abs(x3 - x)});
    ans = max({ans, abs(x2 - x1), abs(y2 - y1), abs(y3 - y1), abs(x3 - x1)});
    ans = max({ans, y3 - y2, x3 - x2});

    

    cout << ans * ans << endl;
}