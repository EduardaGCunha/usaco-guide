#include <bits/stdc++.h>
using namespace std;

int x, y, m;

int brute(int val, int last){
    if(val < 0) return val + last;
    return min(brute(val - x, x), brute(val - y, y));
}

//too slow, only worked on 9/10 cases, so I must revisit this approach after studying DP
int main(){
    freopen("pails.in", "r", stdin);
    freopen("pails.out", "w", stdout);
    cin >> x >> y >> m;
    cout << m - brute(m, 0) << endl;
}