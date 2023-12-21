#include <bits/stdc++.h>
using namespace std;

int main(){
    freopen("paint.in", "r", stdin);
    freopen("paint.out", "w", stdout);
    int n, m, x, y; 
    cin >> n >> m >> x >> y;
    int t = (m - n) + (y - x);
    int i = max(min(m, y) - max(n, x), 0);
    cout << t - i << endl;
}