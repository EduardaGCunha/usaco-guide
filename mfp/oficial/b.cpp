#include <bits/stdc++.h>
using namespace std;

int main(){
    int x1, y1, x2, y2;
    x1 = y2 = INT_MAX;
    y1 = x2 = INT_MIN;
    for(int i = 0; i < 4; i++){
        int c, d; cin >> c >> d;
        x1 = min(c, x1);
        x2 = max(c, x2);
        y1 = max(d, y1);
        y2 = min(d, y2);
    }

    cout << abs(x1 - x2) * abs(y1-y2) << endl;
}