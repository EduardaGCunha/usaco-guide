#include <bits/stdc++.h>
using namespace std;

#define int long long
#define double long double
const int MAXN = 1e5;
int n, t;
int fr[MAXN];
int sp[MAXN];

bool check(double s){
    double right = 1e9, left = -1e9;
    for(int i = 0; i < n; i++){
        right = min(right, fr[i] + s*sp[i]);
        left = max(left, fr[i] - s*sp[i]);
    }
    return right >= left;
}

signed main(){
    cin >> n;
    t = 1e18;
    for(int i = 0; i < n; i++) cin >> fr[i];
    for(int i = 0; i < n; i++) cin >> sp[i];
    double l = 0, r = 1e18;
    for(int i = 0; i < 100; i++){
        double mid = (l+r)/2;
        if(check(mid)){
            r = mid;
        }else{
            l = mid;
        }
    }
    cout << setprecision(9) << l << endl;
}