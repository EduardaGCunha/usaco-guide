#include <bits/stdc++.h>
using namespace std;

#define int long long
int n, x, y;

bool check(int s){
    s -= min(x, y);
    //cout << s/x << " " << s/y << " " << s/x + s/y << endl;
    return (s/x)+(s/y) >= n-1;
}

signed main(){
    cin >> n >> x >> y;
    int l = min(x, y), r = 2*(1e16);
    while(l < r){
        int mid = (l+r)/2;
        if(check(mid)){
            r = mid;
        }else{
            l = mid + 1;
        }
    }
    cout << l << endl;
}